/*
 * Copyright © 2013 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef MESH_H_
#define MESH_H_

#include <memory>
#include <vector>

#include <GL/glew.h>

#include "MeshData.h"
#include "Model.h"

namespace simplicity
{
	class MeshBuffer;

	/**
	 * <p>
	 * A collection of (possibly indexed) vertices stored in a buffer.
	 * </p>
	 */
	class SIMPLE_API Mesh : public Model
	{
		public:
			/**
			 * <p>
			 * An ID unique to the this model class.
			 * </p>
			 */
			static const unsigned int TYPE_ID = 13;

			/**
			 * <p>
			 * @param buffer The buffer to store the (possibly indexed) vertices in.
			 * </p>
			 */
			Mesh(std::shared_ptr<MeshBuffer> buffer);

			/**
			 * <p>
			 * Retrieves the buffeer the (possibly indexed) vertices are stored in.
			 * </p>
			 *
			 * @return The buffeer the (possibly indexed) vertices are stored in.
			 */
			MeshBuffer* getBuffer() const;

			const Vector4& getColor() const override;

			/**
			 * <p>
			 * Retrieves the (possibly indexed) vertex data. Every call to this function should be matched with a call
			 * to releaseData when you are finished with the data.
			 * </p>
			 *
			 * <p>
			 * Prefer the const overload of this function if you do not need to write to this buffer.
			 * </p>
			 *
			 * @param readable Determines whether the data returned should be readable.
			 *
			 * @return The (possibly indexed) vertex data.
			 */
			MeshData& getData(bool readable);

			/**
			 * <p>
			 * Retrieves the (possibly indexed) vertex data. Every call to this function should be matched with a call
			 * to releaseData when you are finished with the data.
			 * </p>
			 *
			 * @return The (possibly indexed) vertex data.
			 */
			const MeshData& getData() const;

			Texture* getNormalMap() const override;

			Texture* getTexture() const override;

			unsigned short getTypeID() const override;

			bool isVisible() const override;

			/**
			 * <p>
			 * Releases the (possibly indexed) vertex data.
			 * </p>
			 */
			void releaseData() const;

			void setColor(const Vector4& color) override;

			void setNormalMap(Texture* normalMap) override;

			void setTexture(Texture* texture) override;

			void setVisible(bool visible) override;

		private:
			std::shared_ptr<MeshBuffer> buffer;

			Vector4 color;

			bool visible;
	};
}

#endif /* MESH_H_ */
