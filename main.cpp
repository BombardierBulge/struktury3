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
    insertFile << "size,average_time_nano_s\n";
    removeFile << "size,average_time_nano_s\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);

    // Test dodawania
    for (int s = 0; s < numSizes; ++s) {
        int size = sizes[s];
        double totalInsertTime = 0;
        for (int trial = 0; trial < numTrials; ++trial) {
            std::vector<int> keys(size);
            std::vector<int> values(size);
            for (int i = 0; i < size; ++i) {
                keys[i] = dist(gen);
                values[i] = dist(gen);
            }
            int newKey = dist(gen);
            int newValue = dist(gen);

            HashTableAVL dict(size * 2);
            for (int i = 0; i < size; ++i)
                dict.insert(keys[i], values[i]);

            Timer timer;
            timer.reset();
            dict.insert(newKey, newValue);
            timer.stop();
            totalInsertTime += timer.measurement_nano();
        }
        double avgInsert = totalInsertTime / numTrials;
        insertFile << size << "," << avgInsert << "\n";
        std::cout << "[AVL][Insert] Size: " << size << " | Insert: " << avgInsert << " ns\n";
    }

    // Test usuwania (losowy klucz)
    for (int s = 0; s < numSizes; ++s) {
        int size = sizes[s];
        double totalRemoveTime = 0;
        for (int trial = 0; trial < numTrials; ++trial) {
            std::vector<int> keys(size);
            std::vector<int> values(size);
            for (int i = 0; i < size; ++i) {
                keys[i] = dist(gen);
                values[i] = dist(gen);
            }

            HashTableAVL dict(size * 2);
            for (int i = 0; i < size; ++i)
                dict.insert(keys[i], values[i]);

            std::uniform_int_distribution<int> remove_dist(0, size - 1);
            int remove_idx = remove_dist(gen);

            Timer timer;
            timer.reset();
            dict.remove(keys[remove_idx]);
            timer.stop();
            totalRemoveTime += timer.measurement_nano();
        }
        double avgRemove = totalRemoveTime / numTrials;
        removeFile << size << "," << avgRemove << "\n";
        std::cout << "[AVL][Remove] Size: " << size << " | Remove: " << avgRemove << " ns\n";
    }
}

void benchmark_chaining(int numTrials, const int* sizes, int numSizes) {
    std::ofstream insertFile("./wyniki/insert_chaining.csv");
    std::ofstream removeFile("./wyniki/remove_chaining.csv");
    insertFile << "size,average_time_nano_s\n";
    removeFile << "size,average_time_nano_s\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);

    // Test dodawania
    for (int s = 0; s < numSizes; ++s) {
        int size = sizes[s];
        double totalInsertTime = 0;
        for (int trial = 0; trial < numTrials; ++trial) {
            std::vector<int> keys(size);
            for (int i = 0; i < size; ++i)
                keys[i] = dist(gen);
            int newKey = dist(gen);

            HashTableChaining dict(size * 2);
            for (int i = 0; i < size; ++i)
                dict.insert(keys[i]);

            Timer timer;
            timer.reset();
            dict.insert(newKey);
            timer.stop();
            totalInsertTime += timer.measurement_nano();
        }
        double avgInsert = totalInsertTime / numTrials;
        insertFile << size << "," << avgInsert << "\n";
        std::cout << "[Chaining][Insert] Size: " << size << " | Insert: " << avgInsert << " ns\n";
    }

    // Test usuwania (losowy klucz)
    for (int s = 0; s < numSizes; ++s) {
        int size = sizes[s];
        double totalRemoveTime = 0;
        for (int trial = 0; trial < numTrials; ++trial) {
            std::vector<int> keys(size);
            for (int i = 0; i < size; ++i)
                keys[i] = dist(gen);

            HashTableChaining dict(size * 2);
            for (int i = 0; i < size; ++i)
                dict.insert(keys[i]);

            std::uniform_int_distribution<int> remove_dist(0, size - 1);
            int remove_idx = remove_dist(gen);

            Timer timer;
            timer.reset();
            dict.remove(keys[remove_idx]);
            timer.stop();
            totalRemoveTime += timer.measurement_nano();
        }
        double avgRemove = totalRemoveTime / numTrials;
        removeFile << size << "," << avgRemove << "\n";
        std::cout << "[Chaining][Remove] Size: " << size << " | Remove: " << avgRemove << " ns\n";
    }
}

void benchmark_linear(int numTrials, const int* sizes, int numSizes) {
    std::ofstream insertFile("./wyniki/insert_linear.csv");
    std::ofstream removeFile("./wyniki/remove_linear.csv");
    insertFile << "size,average_time_nano_s\n";
    removeFile << "size,average_time_nano_s\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);

    // Test dodawania
    for (int s = 0; s < numSizes; ++s) {
        int size = sizes[s];
        double totalInsertTime = 0;
        for (int trial = 0; trial < numTrials; ++trial) {
            std::vector<int> keys(size);
            for (int i = 0; i < size; ++i)
                keys[i] = dist(gen);
            int newKey = dist(gen);

            HashTableLinearProbing dict(size * 2);
            for (int i = 0; i < size; ++i)
                dict.insert(keys[i]);

            Timer timer;
            timer.reset();
            dict.insert(newKey);
            timer.stop();
            totalInsertTime += timer.measurement_nano();
        }
        double avgInsert = totalInsertTime / numTrials;
        insertFile << size << "," << avgInsert << "\n";
        std::cout << "[Linear][Insert] Size: " << size << " | Insert: " << avgInsert << " ns\n";
    }

    // Test usuwania (losowy klucz)
    for (int s = 0; s < numSizes; ++s) {
        int size = sizes[s];
        double totalRemoveTime = 0;
        for (int trial = 0; trial < numTrials; ++trial) {
            std::vector<int> keys(size);
            for (int i = 0; i < size; ++i)
                keys[i] = dist(gen);

            HashTableLinearProbing dict(size * 2);
            for (int i = 0; i < size; ++i)
                dict.insert(keys[i]);

            std::uniform_int_distribution<int> remove_dist(0, size - 1);
            int remove_idx = remove_dist(gen);

            Timer timer;
            timer.reset();
            dict.remove(keys[remove_idx]);
            timer.stop();
            totalRemoveTime += timer.measurement_nano();
        }
        double avgRemove = totalRemoveTime / numTrials;
        removeFile << size << "," << avgRemove << "\n";
        std::cout << "[Linear][Remove] Size: " << size << " | Remove: " << avgRemove << " ns\n";
    }
}

int main() {
    const int sizes[] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000,500000,1000000};
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