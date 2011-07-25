/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ENGINEINPUTCODEC_H_
#define ENGINEINPUTCODEC_H_

namespace simplicity
{
  /**
   * <p>
   * Compresses and decompresses {@link simplicity::EngineInput EngineInput}s.
   * </p>
   *
   * @author Gary Buyn
   */
  class EngineInputCodec
  {
    public:
      /**
       * <p>
       * Compresses the given {@link simplicity::EngineInput EngineInput} to a sequence of bytes.
       * </p>
       *
       * @param input The <code>EngineInput</code> to compress.
       * @param compressedInput The sequence of bytes in which to save the compressed <code>EngineInput</code>.
       *
       * @return The length of the information saved to the sequence of bytes.
       */
      int
      compressEngineInput(const EngineInput& input, const std::vector<char> compressedInput);

      /**
       * <p>
       * Decompresses the given sequence of bytes to an {@link simplicity::EngineInput EngineInput}.
       * </p>
       *
       * @param compressedInput The sequence of bytes to decompress to an <code>EngineInput</code>.
       * @param compressedInputLength The length of the sequence of bytes to decompress to an <code>EngineInput</code>.
       *
       * @return The decompressed <code>EngineInput</code>.
       */
      EngineInput&
      decompressEngineInput(const std::vector<char> compressedInput, const int compressedInputLength);
  };
}

#endif /* ENGINEINPUTCODEC_H_ */
