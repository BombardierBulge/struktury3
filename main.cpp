#include "structures/hashtable_avl.hpp"
#include "structures/HashTableChaining.hpp"
#include "structures/HashTableLinearProbing.hpp"
#include "timer/timer.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <random>
#include <string>

void benchmark_avl(int numTrials, const int* sizes, int numSizes) {
    std::ofstream insertFile("./wyniki/insert_avl.csv");
    std::ofstream removeFile("./wyniki/remove_avl.csv");
    insertFile << "size,average_time_micro_s\n";
    removeFile << "size,average_time_micro_s\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);

    for (int s = 0; s < numSizes; ++s) {
        int size = sizes[s];
        double totalInsertTime = 0;
        double totalRemoveTime = 0;
        for (int trial = 0; trial < numTrials; ++trial) {
            std::vector<int> keys(size), values(size);
            for (int i = 0; i < size; ++i) {
                keys[i] = dist(gen);
                values[i] = dist(gen);
            }
            HashTableAVL dict(size);
            Timer timer;
            timer.reset();
            for (int i = 0; i < size; ++i)
                dict.insert(keys[i], values[i]);
            timer.stop();
            totalInsertTime += timer.measurement_micro();

            timer.reset();
            for (int i = 0; i < size; ++i)
                dict.remove(keys[i]);
            timer.stop();
            totalRemoveTime += timer.measurement_micro();
        }
        double avgInsert = totalInsertTime / numTrials;
        double avgRemove = totalRemoveTime / numTrials;
        std::cout << "[AVL] Size: " << size << " | Insert: " << avgInsert << " us | Remove: " << avgRemove << " us\n";
        insertFile << size << "," << avgInsert << "\n";
        removeFile << size << "," << avgRemove << "\n";
    }
}

void benchmark_chaining(int numTrials, const int* sizes, int numSizes) {
    std::ofstream insertFile("./wyniki/insert_chaining.csv");
    std::ofstream removeFile("./wyniki/remove_chaining.csv");
    insertFile << "size,average_time_micro_s\n";
    removeFile << "size,average_time_micro_s\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);

    for (int s = 0; s < numSizes; ++s) {
        int size = sizes[s];
        double totalInsertTime = 0;
        double totalRemoveTime = 0;
        for (int trial = 0; trial < numTrials; ++trial) {
            std::vector<int> keys(size);
            for (int i = 0; i < size; ++i)
                keys[i] = dist(gen);
            HashTableChaining dict;
            Timer timer;
            timer.reset();
            for (int i = 0; i < size; ++i)
                dict.insert(keys[i]);
            timer.stop();
            totalInsertTime += timer.measurement_micro();

            timer.reset();
            for (int i = 0; i < size; ++i) {
                dict.remove(keys[i]);
            }
            timer.stop();
            totalRemoveTime += timer.measurement_micro();
        }
        double avgInsert = totalInsertTime / numTrials;
        double avgRemove = totalRemoveTime / numTrials;
        std::cout << "[Chaining] Size: " << size << " | Insert: " << avgInsert << " us | Remove: " << avgRemove << " us\n";
        insertFile << size << "," << avgInsert << "\n";
        removeFile << size << "," << avgRemove << "\n";
    }
}

void benchmark_linear(int numTrials, const int* sizes, int numSizes) {
    std::ofstream insertFile("./wyniki/insert_linear.csv");
    std::ofstream removeFile("./wyniki/remove_linear.csv");
    insertFile << "size,average_time_micro_s\n";
    removeFile << "size,average_time_micro_s\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);

    for (int s = 0; s < numSizes; ++s) {
        int size = sizes[s];
        double totalInsertTime = 0;
        double totalRemoveTime = 0;
        for (int trial = 0; trial < numTrials; ++trial) {
            std::vector<int> keys(size);
            for (int i = 0; i < size; ++i)
                keys[i] = dist(gen);
            HashTableLinearProbing dict;
            Timer timer;
            timer.reset();
            for (int i = 0; i < size; ++i)
                dict.insert(keys[i]);
            timer.stop();
            totalInsertTime += timer.measurement_micro();

            timer.reset();
            for (int i = 0; i < size; ++i) {
                dict.remove(keys[i]);
            }
            timer.stop();
            totalRemoveTime += timer.measurement_micro();
        }
        double avgInsert = totalInsertTime / numTrials;
        double avgRemove = totalRemoveTime / numTrials;
        std::cout << "[Linear] Size: " << size << " | Insert: " << avgInsert << " us | Remove: " << avgRemove << " us\n";
        insertFile << size << "," << avgInsert << "\n";
        removeFile << size << "," << avgRemove << "\n";
    }
}

int main() {
    const int sizes[] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    const int numTrials = 100;

    std::filesystem::create_directories("./wyniki");

    std::cout << "Wybierz algorytm do benchmarku:\n";
    std::cout << "1 - HashTableAVL \n";
    std::cout << "2 - HashTableChaining \n";
    std::cout << "3 - HashTableLinearProbing \n";
    std::cout << "4 - Wszystkie\n";
    std::cout << "Twoj wybor: ";
    int wybor;
    std::cin >> wybor;

    if (wybor == 1) benchmark_avl(numTrials, sizes, numSizes);
    else if (wybor == 2) benchmark_chaining(numTrials, sizes, numSizes);
    else if (wybor == 3) benchmark_linear(numTrials, sizes, numSizes);
    else if (wybor == 4) {
        benchmark_avl(numTrials, sizes, numSizes);
        benchmark_chaining(numTrials, sizes, numSizes);
        benchmark_linear(numTrials, sizes, numSizes);
    } else {
        std::cout << "Nieprawidlowy wybor.\n";
    }

    std::cout << "Benchmark end" << std::endl;
    return 0;
}