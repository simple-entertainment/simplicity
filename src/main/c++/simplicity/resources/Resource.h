/*
 * Copyright © 2014 Simple Entertainment Limited
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
#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <istream>
#include <memory>
#include <ostream>
#include <string>

#include "../common/Defines.h"

namespace simplicity
{
	/**
	 * <p>
	 * A data resource.
	 * </p>
	 */
	class SIMPLE_API Resource
	{
		public:
			/**
			 * <p>
			 * The type of the resource.
			 * </p>
			 *
			 * <p>
			 * Different resource types are kept in different (platform-specific) locations and have different
			 * permissions.
			 * </p>
			 */
			enum class Type
			{
				ASSET, /**< Read-only resources packaged with the application. */
				CONSOLE, /**< The console... */ // TODO Does this make sense?
				USER /**< Read-write resources specific to the current user. */
			};

			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Resource()
			{
			}

			/**
			 * <p>
			 * Appends data to this resource.
			 * </p>
			 *
			 * <p>
			 * While this function is convenient for one-off data appending, it could be slow if called many times
			 * since it creates a stream each time. In that case, consider using getOutputStream().
			 * </p>
			 *
			 * @param data The data.
			 * @param length The length of the data.
			 */
			virtual void appendData(const char* data, unsigned int length) = 0;

			/**
			 * <p>
			 * Appends data to this resource.
			 * </p>
			 *
			 * <p>
			 * While this function is convenient for one-off data appending, it could be slow if called many times
			 * since it creates a stream each time. In that case, consider using getOutputStream().
			 * </p>
			 *
			 * @param data The data.
			 */
			virtual void appendData(const std::string& data) = 0;

			/**
			 * <p>
			 * Retrieves the data from this resource.
			 * </p>
			 *
			 * @return The data.
			 */
			virtual std::string getData() const = 0;

			/**
			 * <p>
			 * Retrieves an input stream for reading data from this resource. Each time this function is called a new
			 * stream is created.
			 * </p>
			 *
			 * <p>
			 * Some resources may not support this function and will return nullptr.
			 * </p>
			 *
			 * @return An input stream for this resource.
			 */
			virtual std::unique_ptr<std::istream> getInputStream() const = 0;

			/**
			 * <p>
			 * Retrieves the name of this resource.
			 * </p>
			 *
			 * @return The name of this resource.
			 */
			virtual const std::string& getName() const = 0;

			/**
			 * <p>
			 * Retrieves an output stream for writing data to this resource. Each time this function is called a new
			 * stream is created.
			 * </p>
			 *
			 * <p>
			 * Some resources may not support this function and will return nullptr.
			 * </p>
			 *
			 * @return An output stream for this resource.
			 */
			virtual std::unique_ptr<std::ostream> getOutputStream(bool append = true) = 0;

			/**
			 * <p>
			 * Retrieves the type of this resource.
			 * </p>
			 *
			 * @return The type of this resource.
			 */
			virtual Type getType() const = 0;

			/**
			 * <p>
			 * Retrieves the URI of this resource.
			 * </p>
			 *
			 * @return The URI of this resource.
			 */
			virtual std::string getUri() const = 0;

			/**
			 * <p>
			 * Determines if this resource contains binary data.
			 * </p>
			 *
			 * @return True if the resource contains binary data, false otherwise.
			 */
			virtual bool isBinary() const = 0;

			/**
			 * <p>
			 * Sets the data of this resource.
			 * </p>
			 *
			 * @param data The data.
			 * @param length The length of the data.
			 */
			virtual void setData(const char* data, unsigned int length) = 0;

			/**
			 * <p>
			 * Sets the data of this resource.
			 * </p>
			 *
			 * @param data The data.
			 */
			virtual void setData(const std::string& data) = 0;
	};
}

#endif /* RESOURCE_H_ */
