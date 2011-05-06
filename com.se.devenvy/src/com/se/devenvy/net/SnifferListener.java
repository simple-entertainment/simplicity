/*
    This file is part of Dev Envy.

    Dev Envy is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    Dev Envy is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with Dev Envy. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.devenvy.net;

import java.net.InetAddress;
import java.util.List;

/**
 * <p>
 * Responds to events fired by a {@link Sniffer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface SnifferListener
{
    /**
     * <p>
     * Called when a device is found during a sniff.
     * </p>
     * 
     * @param address The address of the device that was found.
     */
    void deviceFound(InetAddress address);

    /**
     * <p>
     * Called when a sniff is completed.
     * </p>
     * 
     * @param addresses The addresses of the devices that were found.
     */
    void sniffComplete(List<InetAddress> addresses);
}
