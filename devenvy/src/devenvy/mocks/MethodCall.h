/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef METHODCALL_H_
#define METHODCALL_H_

#include <boost/any.hpp>
#include <string>
#include <vector>
using namespace boost;
using namespace std;

namespace devenvy
{
    /**
     * <p>
     * A method call that has been made to a {@link devenvy::MockObject MockObject}.
     * </p>
     *
     * @author Gary Buyn
     */
    class MethodCall
    {
        public:
            /**
             * <p>
             * The name of the method called.
             * </p>
             */
            string name;

            /**
             * <p>
             * The parameters passed to the method.
             * </p>
             */
            vector<any> parameters;

            /**
             * <p>
             * Creates an instance of <code>MethodCall</code>.
             * </p>
             */
            MethodCall();

            /**
             * <p>
             * Disposes of an instance of <code>MethodCall</code>.
             * </p>
             */
            virtual
            ~MethodCall();
    };
}

#endif /* METHODCALL_H_ */
