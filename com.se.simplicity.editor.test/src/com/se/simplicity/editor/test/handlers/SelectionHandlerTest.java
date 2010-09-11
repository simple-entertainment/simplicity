/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.handlers;

import static org.easymock.EasyMock.anyObject;
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
import org.eclipse.swt.widgets.Event;
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.ISources;
import org.eclipse.ui.IWorkbenchPage;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.handlers.RadioState;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.se.simplicity.editor.handlers.SelectionHandler;
import com.se.simplicity.editor.internal.event.SceneChangedEvent;
import com.se.simplicity.editor.ui.editors.SceneEditor;
import com.se.simplicity.editor.ui.views.SceneComponentView;
import com.se.simplicity.editor.ui.views.SceneOutlineView;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.handlers.SelectionHandler SelectionHandler}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SelectionHandlerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SelectionHandler testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SelectionHandler();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.SelectionHandler#execute(ExecutionEvent) execute(ExecutionEvent)}.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test
    public void execute() throws ExecutionException
    {
        // Create dependencies.
        ModelNode mockNode = createMock(ModelNode.class);

        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);
        IWorkbenchWindow mockWorkbenchWindow = createMock(IWorkbenchWindow.class);
        IWorkbenchPage mockWorkbenchPage = createMock(IWorkbenchPage.class);
        SceneOutlineView mockOutlineView = createMock(SceneOutlineView.class);
        SceneComponentView mockComponentView = createMock(SceneComponentView.class);

        CommandManager commandManager = new CommandManager();
        Command command = commandManager.getCommand("test");
        Event event = new Event();
        event.data = mockNode;
        State mockState = createMock(State.class);
        command.addState(RadioState.STATE_ID, mockState);
        HashMap<String, String> parameters = new HashMap<String, String>();
        parameters.put(RadioState.PARAMETER_ID, "node1,face0");
        ExecutionEvent executionEvent = new ExecutionEvent(command, parameters, event, mockContext);

        // Dictate correct behaviour.
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        expect(mockContext.getVariable(ISources.ACTIVE_WORKBENCH_WINDOW_NAME)).andStubReturn(mockWorkbenchWindow);
        expect(mockState.getValue()).andStubReturn("node0,face0");
        expect(mockWorkbenchWindow.getActivePage()).andStubReturn(mockWorkbenchPage);
        expect(mockWorkbenchPage.findView("com.se.simplicity.editor.ui.views.SceneOutlineView")).andStubReturn(mockOutlineView);
        expect(mockWorkbenchPage.findView("com.se.simplicity.editor.ui.views.SceneComponentView")).andStubReturn(mockComponentView);
        expect(mockWorkbenchPage.getActiveEditor()).andStubReturn(mockSceneEditor);
        replay(mockContext, mockWorkbenchWindow, mockWorkbenchPage);

        // Dictate expected results.
        mockOutlineView.sceneChanged((SceneChangedEvent) anyObject());
        mockComponentView.sceneChanged((SceneChangedEvent) anyObject());
        mockSceneEditor.setSelectedSceneComponent(mockNode);
        mockState.setValue("node1,face0");
        replay(mockState, mockOutlineView, mockComponentView, mockSceneEditor);

        // Perform test.
        testObject.execute(executionEvent);

        // Verify results.
        verify(mockOutlineView, mockComponentView, mockSceneEditor);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.SelectionHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
     * special condition that the radio parameter is the same as the current radio state.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test
    @Ignore
    public void executeSame() throws ExecutionException
    {
        // Create dependencies.
        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);

        CommandManager commandManager = new CommandManager();
        Command command = commandManager.getCommand("test");
        State mockState = createMock(State.class);
        command.addState(RadioState.STATE_ID, mockState);
        HashMap<String, String> parameters = new HashMap<String, String>();
        parameters.put(RadioState.PARAMETER_ID, "node0,face0");
        ExecutionEvent event = new ExecutionEvent(command, parameters, null, mockContext);

        // Dictate correct behaviour.
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        expect(mockState.getValue()).andStubReturn("node0,face0");
        replay(mockContext);

        // Dictate expected results.
        replay(mockState); // Nothing should be called on these.

        // Perform test.
        testObject.execute(event);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.handlers.SelectionHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
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
     * Unit test the method {@link com.se.simplicity.editor.handlers.SelectionModeHandler#execute(ExecutionEvent) execute(ExecutionEvent)} with the
     * special condition that the handler was executed from a Widget pick with no hits.
     * </p>
     * 
     * @throws ExecutionException Thrown if the handler fails to execute.
     */
    @Test
    public void executeWidgetPickNoHits() throws ExecutionException
    {
        // Create dependencies.
        IEvaluationContext mockContext = createMock(IEvaluationContext.class);
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);

        CommandManager commandManager = new CommandManager();
        Command command = commandManager.getCommand("test");
        Event event = new Event();
        event.type = 1;
        event.data = null;
        State mockState = createMock(State.class);
        command.addState(RadioState.STATE_ID, mockState);
        HashMap<String, String> parameters = new HashMap<String, String>();
        parameters.put(RadioState.PARAMETER_ID, "none");
        ExecutionEvent executionEvent = new ExecutionEvent(command, parameters, event, mockContext);

        // Dictate correct behaviour.
        expect(mockContext.getVariable(ISources.ACTIVE_EDITOR_NAME)).andStubReturn(mockSceneEditor);
        expect(mockState.getValue()).andStubReturn("node0,face0");
        replay(mockContext);

        // Dictate expected results.
        replay(mockSceneEditor, mockState); // Nothing should be called on these.

        // Perform test.
        testObject.execute(executionEvent);

        // Verify results.
        verify(mockSceneEditor);
    }
}
