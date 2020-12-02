#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
/*
 *
 * --- Day 1: Report Repair ---
 * Before you leave, the Elves in accounting just need you to fix your expense report (your puzzle input); apparently, something isn't quite adding up.
 *
 * Specifically, they need you to find the two entries that sum to 2020 and then multiply those two numbers together.
 *
 * For example, suppose your expense report contained the following:
 *
 * 1721
 * 979
 * 366
 * 299
 * 675
 * 1456
 *
 * In this list, the two entries that sum to 2020 are 1721 and 299. Multiplying them together produces 1721 * 299 = 514579, so the correct answer is 514579.
 *
 * Of course, your expense report is much larger. Find the two entries that sum to 2020; what do you get if you multiply them together?
 * --- Part Two ---
 * Using the above example again, the three entries that sum to 2020 are 979, 366, and
 *  675. Multiplying them together produces the answer, 241861950.

 In your expense report, what is the product of the three entries that sum to 2020?
*/
// #define DEBUG
template<typename t_streamable>
void debug_message(t_streamable message)
{
#ifdef DEBUG
    std::cout << "advent_of_code DEBUG:" << message << "\n";
#endif
}

int day_1(bool use_stdin = false)
{
    // iostream performance hack
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    // Main code
    int answer = 0;
    std::ifstream test_input("day1-input");
    std::vector<int> test_input_formatted;
    test_input_formatted.reserve(100);
    int count = 0;
    for (; !test_input.eof() ;)
    {
        static int tmp;
        test_input >> tmp;
        test_input_formatted.push_back(tmp);
    }
    test_input_formatted.shrink_to_fit();
    test_input.close();
    bool answer_not_found = true;
    int input_position[] = {0, 0, 0};
    unsigned search_pass = 0;
    // debug_message("input size");
    // debug_message(test_input_formatted.size());
    do
    {
        debug_message(input_position[0]);
        const int combo1 = test_input_formatted[input_position[1-1]];
        const int combo2 = test_input_formatted[input_position[2-1]];
        const int combo3 = test_input_formatted[input_position[3-1]];
        int sum = combo1 + combo2 + combo3;
        if (sum == 2020)
        {
            int answer_product = combo1 * combo2 * combo3;
            debug_message("Presumed answer components:");
            debug_message(combo1);
            debug_message(combo2);
            debug_message(combo3);
            std::cout << "Answer Product:" << answer_product;
            answer_not_found = false;
        }
        // debug_message("Search pass:");
        // debug_message(input_position[search_pass]);
        ++input_position[0];

        if (input_position[0] >= test_input_formatted.size())
        {
            input_position[0] = 0;
            ++input_position[1];
            if (input_position[1] >= test_input_formatted.size())
            {
                input_position[1] = 0;
                ++input_position[2];
                if (input_position[2] == test_input_formatted.size() && answer_not_found)
                {
                    std::cout << "Answer not found: Exiting";
                    return EXIT_FAILURE;
                }
            }
        }
       
    } while (answer_not_found);
    return EXIT_SUCCESS;

// for (const int& interogated : test_input_formatted)
    // {
    //     for (const int& interogator_1 : test_input_formatted)
    //     {
    //         for (const int& interogator_2 : test_input_formatted)
    //         {
    //             int result = interogated + interogator_1 + interogator_2;
    //             debug_message(std::to_string(result));
    //             // debug_message("" + std::to_string(result == 2020));
    //             if (result == 2020)
    //             {
    //                 answer = interogated * interogator_1 * interogator_2;
    //                 debug_message(std::to_string(answer));
    //                 std::cout << answer << "\n";
    //                 test_input.close();
    //                 return EXIT_SUCCESS;
    //             }
    //         }
    //     }
    // }
}

int main(int argc, char** argv)
{
    std::vector<int> puzzle_progress =
        {
            day_1(),
        };


    return EXIT_SUCCESS;
}
