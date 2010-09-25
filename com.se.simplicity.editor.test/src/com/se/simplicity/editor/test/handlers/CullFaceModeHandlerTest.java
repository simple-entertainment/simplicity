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
import org.eclipse.ui.handlers.RegistryToggleState;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.handlers.CullFaceModeHandler;
import com.se.simplicity.editor.ui.editors.SceneEditor;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.handlers.CullFaceModeHandler CullFaceModeHandler}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class CullFaceModeHandlerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private CullFaceModeHandler testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new CullFaceModeHandler();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.ProjectionModeHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
     * special condition that the toggle parameter was 'false'.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test
    public void executeFalse() throws ExecutionException
    {
        // Create dependencies.
        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);

        CommandManager commandManager = new CommandManager();
        Command command = commandManager.getCommand("test");
        State mockState = createMock(State.class);
        command.addState(RegistryToggleState.STATE_ID, mockState);
        ExecutionEvent event = new ExecutionEvent(command, new HashMap<String, String>(), null, mockContext);

        // Dictate correct behaviour.
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        expect(mockState.getValue()).andStubReturn(true);
        replay(mockContext);

        // Dictate expected results.
        mockSceneEditor.setCullFaceMode(false);
        mockState.setValue(false);
        replay(mockSceneEditor, mockState);

        // Perform test.
        testObject.execute(event);

        // Verify test results.
        verify(mockSceneEditor);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.ProjectionModeHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
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
     * Unit test the method {@link com.se.simplicity.editor.handlers.ProjectionModeHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
     * special condition that the toggle parameter was 'true'.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test
    public void executeTrue() throws ExecutionException
    {
        // Create dependencies.
        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);

        CommandManager commandManager = new CommandManager();
        Command command = commandManager.getCommand("test");
        State mockState = createMock(State.class);
        command.addState(RegistryToggleState.STATE_ID, mockState);
        ExecutionEvent event = new ExecutionEvent(command, new HashMap<String, String>(), null, mockContext);

        // Dictate correct behaviour.
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        expect(mockState.getValue()).andStubReturn(false);
        replay(mockContext);

        // Dictate expected results.
        mockSceneEditor.setCullFaceMode(true);
        mockState.setValue(true);
        replay(mockSceneEditor, mockState);

        // Perform test.
        testObject.execute(event);

        // Verify test results.
        verify(mockSceneEditor);
    }
}
