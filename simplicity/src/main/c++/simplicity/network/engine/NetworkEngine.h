/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef NETWORKENGINE_H_
#define NETWORKENGINE_H_

#include "../../engine/Engine.h"
#include "../../engine/EngineInputCodec.h"
#include "EngineProtocol.h"

namespace simplicity
{
  /**
   * <p>
   * TODO
   * </p>
   *
   * @author Gary Buyn
   */
  class NetworkEngine : public Engine
  {
    public:
      /**
       * <p>
       * Retrieves the {@link simplicity::EngineInputCodec EngineInputCodec} used to compress and decompress the
       * {@link simplicity::EngineInput EngineInput} input to this <code>ClientEngine</code>.
       * </p>
       *
       * @return The <code>EngineInputCodec</code> used to compress and decompress the <code>EngineInput</code> input to this
       * <code>ClientEngine</code>.
       */
      boost::shared_ptr<EngineInputCodec>
      getInputCodec();

      /**
       * <p>
       * Retrieves the maximum number of bytes that can be received and decompressed to create an {@link simplicity::EngineInput EngineInput}.
       * </p>
       *
       * @return The maximum number of bytes that can be received and decompressed to create an <code>EngineInput</code>.
       */
      int
      getMaxReceivable() const;

      /**
       * <p>
       * Retrieves the maximum number of bytes that the {@link simplicity::EngineInput EngineInput} can be compressed to to create the message to be
       * sent to the {@link simplicity::ServerEngine ServerEngine}.
       * </p>
       *
       * @return The maximum number of bytes that the <code>EngineInput</code> can be compressed to to create the message to be sent to the
       * <code>ServerEngine</code>.
       */
      int
      getMaxSendable() const;

      /**
       * <p>
       * Retrieves the {@link simplicity::EngineInputCodec EngineInputCodec} used to compress and decompress the
       * {@link simplicity::EngineInput EngineInput} output from this <code>ClientEngine</code>.
       * </p>
       *
       * @return The <code>EngineInputCodec</code> used to compress and decompress the <code>EngineInput</code> output from this
       * <code>ClientEngine</code>.
       */
      boost::shared_ptr<EngineInputCodec>
      getOutputCodec() const;

      /**
       * <p>
       * Retrieves the protocol used to communicate between this <code>ClientEngine</code> and the {@link simplicity::ServerEngine ServerEngine}.
       * </p>
       *
       * @return The protocol used to communicate between this <code>ClientEngine</code> and the <code>ServerEngine</code>.
       */
      boost::shared_ptr<EngineProtocol>
      getProtocol() const;

      /**
       * <p>
       * Sets the {@link simplicity::EngineInputCodec EngineInputCodec} used to compress and decompress the
       * {@link simplicity::EngineInput EngineInput} input to this <code>ClientEngine</code>.
       * </p>
       *
       * @param codec The <code>EngineInputCodec</code> used to compress and decompress the <code>EngineInput</code> input to this
       * <code>ClientEngine</code>.
       */
      void
      setInputCodec(boost::shared_ptr<EngineInputCodec> codec);

      /**
       * <p>
       * Sets the maximum number of bytes that can be received and decompressed to create an {@link simplicity::EngineInput EngineInput}.
       * </p>
       *
       * @param maxReceivable The maximum number of bytes that can be received and decompressed to create an <code>EngineInput</code>.
       */
      void
      setMaxReceivable(const int maxReceivable);

      /**
       * <p>
       * Sets the maximum number of bytes that the {@link simplicity::EngineInput EngineInput} can be compressed to to create the message to be sent
       * to the {@link simplicity::ServerEngine ServerEngine}.
       * </p>
       *
       * @param maxSendable The maximum number of bytes that the <code>EngineInput</code> can be compressed to to create the message to be sent to
       * the <code>ServerEngine</code>.
       */
      void
      setMaxSendable(const int maxSendable);

      /**
       * <p>
       * Sets the {@link simplicity::EngineInputCodec EngineInputCodec} used to compress and decompress the
       * {@link simplicity::EngineInput EngineInput} output from this <code>ClientEngine</code>.
       * </p>
       *
       * @param codec The <code>EngineInputCodec</code> used to compress and decompress the <code>EngineInput</code> output from this
       * <code>ClientEngine</code>.
       */
      void
      setOutputCodec(boost::shared_ptr<EngineInputCodec> codec);

      /**
       * <p>
       * Sets the protocol used to communicate between this <code>ClientEngine</code> and the {@link simplicity::ServerEngine ServerEngine}.
       * </p>
       *
       * @param protocol The protocol used to communicate between this <code>ClientEngine</code> and the <code>ServerEngine</code>.
       */
      void
      setProtocol(boost::shared_ptr<EngineProtocol> protocol);
  };
}

#endif /* NETWORKENGINE_H_ */
