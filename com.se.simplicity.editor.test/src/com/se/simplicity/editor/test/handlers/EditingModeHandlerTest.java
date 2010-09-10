/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.handlers;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.verify;

import java.util.HashMap;

import org.eclipse.core.commands.Command;
import org.eclipse.core.commands.CommandManager;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.commands.State;
import org.eclipse.core.expressions.IEvaluationContext;
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.ISources;
import org.eclipse.ui.handlers.RadioState;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.handlers.EditingModeHandler;
import com.se.simplicity.editor.internal.ContentProvider;
import com.se.simplicity.editor.internal.EditingMode;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.ui.editors.SceneEditor;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.handlers.EditingModeHandler EditingModeHandler}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class EditingModeHandlerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private EditingModeHandler testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        SceneManager.getSceneManager().reset();

        testObject = new EditingModeHandler();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.EditingModeHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
     * special condition that the radio parameter was 'rotation'.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test
    public void executeRotation() throws ExecutionException
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        ModelNode mockNode = createMock(ModelNode.class);

        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);
        ContentProvider mockContentProvider = createMock(ContentProvider.class);

        CommandManager commandManager = new CommandManager();
        Command command = commandManager.getCommand("test");
        State mockState = createMock(State.class);
        command.addState(RadioState.STATE_ID, mockState);
        HashMap<String, String> parameters = new HashMap<String, String>();
        parameters.put(RadioState.PARAMETER_ID, "rotation");
        ExecutionEvent event = new ExecutionEvent(command, parameters, null, mockContext);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        expect(mockSceneEditor.getContentProvider()).andStubReturn(mockContentProvider);
        expect(mockState.getValue()).andStubReturn("selection");
        replay(mockScene, mockSceneGraph, mockContext, mockSceneEditor);

        // Initialise test environment.
        SceneManager.getSceneManager().addScene(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene(mockScene);
        SceneManager.getSceneManager().setActiveNode(mockNode);

        // Dictate expected results.
        mockContentProvider.setEditingMode(EditingMode.ROTATION);
        mockState.setValue("rotation");
        replay(mockContentProvider, mockState);

        // Perform test.
        testObject.execute(event);

        // Verify test results.
        verify(mockContentProvider);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.EditingModeHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
     * special condition that a {@link com.se.simplicity.editor.ui.editors.SceneEditor SceneEditor} is not active.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test(expected = ExecutionException.class)
    public void executeSceneEditorNotActive() throws ExecutionException
    {
        // Create dependencies.
        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        IEditorPart mockSceneEditor = createMock(IEditorPart.class);

        ExecutionEvent mockEvent = new ExecutionEvent(null, new HashMap<String, String>(), null, mockContext);

        // Dictate correct behaviour.
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        replay(mockContext, mockSceneEditor);

        // Perform test.
        testObject.execute(mockEvent);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.EditingModeHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
     * special condition that the radio parameter is the same as the current radio state.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test
    public void executeSame() throws ExecutionException
    {
        // Create dependencies.
        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);
        ContentProvider mockContentProvider = createMock(ContentProvider.class);

        CommandManager commandManager = new CommandManager();
        Command command = commandManager.getCommand("test");
        State mockState = createMock(State.class);
        command.addState(RadioState.STATE_ID, mockState);
        HashMap<String, String> parameters = new HashMap<String, String>();
        parameters.put(RadioState.PARAMETER_ID, "selection");
        ExecutionEvent event = new ExecutionEvent(command, parameters, null, mockContext);

        // Dictate correct behaviour.
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        expect(mockSceneEditor.getContentProvider()).andStubReturn(mockContentProvider);
        expect(mockState.getValue()).andStubReturn("selection");
        replay(mockContext, mockSceneEditor);

        // Dictate expected results.
        replay(mockContentProvider, mockState); // Nothing should be called on these.

        // Perform test.
        testObject.execute(event);

        // Verify test results.
        verify(mockContentProvider);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.EditingModeHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
     * special condition that the radio parameter was 'selection'.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test
    public void executeSelection() throws ExecutionException
    {
        // Create dependencies.
        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);
        ContentProvider mockContentProvider = createMock(ContentProvider.class);

        CommandManager commandManager = new CommandManager();
        Command command = commandManager.getCommand("test");
        State mockState = createMock(State.class);
        command.addState(RadioState.STATE_ID, mockState);
        HashMap<String, String> parameters = new HashMap<String, String>();
        parameters.put(RadioState.PARAMETER_ID, "selection");
        ExecutionEvent event = new ExecutionEvent(command, parameters, null, mockContext);

        // Dictate correct behaviour.
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        expect(mockSceneEditor.getContentProvider()).andStubReturn(mockContentProvider);
        expect(mockState.getValue()).andStubReturn("rotation");
        replay(mockContext, mockSceneEditor);

        // Dictate expected results.
        mockContentProvider.setEditingMode(EditingMode.SELECTION);
        mockState.setValue("selection");
        replay(mockContentProvider, mockState);

        // Perform test.
        testObject.execute(event);

        // Verify test results.
        verify(mockContentProvider);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.EditingModeHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
     * special condition that the radio parameter was 'translation'.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test
    public void executeTranslation() throws ExecutionException
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        ModelNode mockNode = createMock(ModelNode.class);

        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);
        ContentProvider mockContentProvider = createMock(ContentProvider.class);

        CommandManager commandManager = new CommandManager();
        Command command = commandManager.getCommand("test");
        State mockState = createMock(State.class);
        command.addState(RadioState.STATE_ID, mockState);
        HashMap<String, String> parameters = new HashMap<String, String>();
        parameters.put(RadioState.PARAMETER_ID, "translation");
        ExecutionEvent event = new ExecutionEvent(command, parameters, null, mockContext);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        expect(mockSceneEditor.getContentProvider()).andStubReturn(mockContentProvider);
        expect(mockState.getValue()).andStubReturn("selection");
        replay(mockScene, mockSceneGraph, mockContext, mockSceneEditor);

        // Initialise test environment.
        SceneManager.getSceneManager().addScene(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene(mockScene);
        SceneManager.getSceneManager().setActiveNode(mockNode);

        // Dictate expected results.
        mockContentProvider.setEditingMode(EditingMode.TRANSLATION);
        mockState.setValue("translation");
        replay(mockContentProvider, mockState);

        // Perform test.
        testObject.execute(event);

        // Verify test results.
        verify(mockContentProvider);
    }
}
