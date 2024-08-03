/*
 * MIT License
 *
 * Copyright (c) 2024 kiyasui-hito
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "virtual_machine/full_adder_circuit.hpp"

#include "virtual_machine/full_adder.hpp"
#include "virtual_machine/gate.hpp"

#include <algorithm>


namespace Koi {
namespace VirtualMachine {

std::vector<bool> FullAdderCircuit::add(std::vector<bool> top_word, std::vector<bool> bottom_word, bool carry_in) {
    std::vector<bool> result(std::max(top_word.size(), bottom_word.size()));

    std::vector<FullAdder::Output> outputs(result.size(), { false, false });

    bool current_carry = carry_in;
    for (unsigned int i = 1u; i < result.size(); ++i) {
        unsigned int result_i = result.size() - i;
        unsigned int top_i = top_word.size() - i;
        unsigned int bottom_i = bottom_word.size() - i;
        unsigned int outputs_i = outputs.size() - i;

        bool top_bit = top_i < top_word.size() && top_word.at(top_i);
        bool bottom_bit = bottom_i < bottom_word.size() && bottom_word.at(bottom_i);

        outputs.at(result_i) = FullAdder::add(
                top_bit,
                Gate::get_exclusive_or(carry_in, bottom_bit),
                current_carry
        );

        current_carry = outputs.at(outputs_i).carry;
    }

    for (unsigned int i = 0u; i < result.size(); ++i) {
        result.at(i) = outputs.at(i).sum;
    }

    return result;
}

} // VirtualMachine
} // Koi