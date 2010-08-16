package com.se.simplicity.engine;

/**
 * <p>
 * An {@link com.se.simplicity.engine.Engine Engine} that is composed of several sub-engines. The <code>CompositeEngine</code>
 * manages how the sub-engines are run.
 * </p>
 * 
 * @author simple
 */
public interface CompositeEngine extends Engine
{
	/**
	 * <p>
	 * Adds an {@link com.se.simplicity.engine.Engine Engine} to the set of engines managed by this <code>CompositeEngine</code>.
	 * </p>
	 * 
	 * @param engine The {@link com.se.simplicity.engine.Engine Engine} to add to the set of engines managed by this
	 * <code>CompositeEngine</code>.
	 */
	void addEngine(Engine engine);

	/**
	 * <p>
	 * Removes an {@link com.se.simplicity.engine.Engine Engine} from the set of engines managed by this
	 * <code>CompositeEngine</code>.
	 * </p>
	 * 
	 * @param engine The {@link com.se.simplicity.engine.Engine Engine} to remove from the set of engines managed by this
	 * <code>CompositeEngine</code>.
	 */
	void removeEngine(Engine engine);
}
