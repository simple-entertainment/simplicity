/**
 * <p>
 * The basis for all models in The Simplicity Engine. The concept of a model is expressed as a tree of specialised nodes, each of which is able to
 * contain a vertex group. This method of modelling allows efficiencies in collision detection and rendering as well as the ability to animate.
 * 
 * Bounding volumes further increase efficiencies in collision detection and rendering as it allows a quick check against the node to be carried out
 * before performing the more complex task of checking the actual geometry.
 * </p>
 */
package com.se.simplicity.model;

