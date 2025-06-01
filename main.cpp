#include "structures/hashtable_avl.hpp"
#include "timer/timer.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <random>

int main() {
    const int sizes[] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
    const int numTrials = 10;

    std::filesystem::create_directories("./wyniki");

    std::ofstream insertFile("./wyniki/insert.csv");
    std::ofstream removeFile("./wyniki/remove.csv");

    insertFile << "size,average_time_micro_s\n";
    removeFile << "size,average_time_micro_s\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);

    std::cout << "Benchmark start" << std::endl;

    for (int size : sizes) {
        double totalInsertTime = 0;
        double totalRemoveTime = 0;

        // Prepare random keys and values for all trials
        std::vector<std::vector<int>> keys_trials(numTrials, std::vector<int>(size));
        std::vector<std::vector<int>> values_trials(numTrials, std::vector<int>(size));
        for (int trial = 0; trial < numTrials; ++trial) {
            for (int i = 0; i < size; ++i) {
                keys_trials[trial][i] = dist(gen);
                values_trials[trial][i] = dist(gen);
            }
        }

        for (int trial = 0; trial < numTrials; ++trial) {
            HashTableAVL dict(size);
            Timer timer;

            // Benchmark insertions
            timer.reset();
            for (int i = 0; i < size; ++i) {
                dict.insert(keys_trials[trial][i], values_trials[trial][i]);
            }
            timer.stop();
            totalInsertTime += timer.measurement_micro();

            // Benchmark removals
            timer.reset();
            for (int i = 0; i < size; ++i) {
                dict.remove(keys_trials[trial][i]);
            }
            timer.stop();
            totalRemoveTime += timer.measurement_micro();
        }

        double avgInsert = totalInsertTime / numTrials;
        double avgRemove = totalRemoveTime / numTrials;

        std::cout << "Average for Size: " << size 
                  << " | Insert Time: " << avgInsert
                  << " ms | Remove Time: " << avgRemove << " micro s\n";

        insertFile << size << "," << avgInsert << "\n";
        removeFile << size << "," << avgRemove << "\n";
    }

    insertFile.close();
    removeFile.close();

    std::cout << "Benchmark end" << std::endl;

    return 0;
}