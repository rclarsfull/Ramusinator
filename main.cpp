//
// Created by lars on 26.05.23.
//
#include <iostream>
#include <cstring>

int main(int argc, char **argv) {

    int fortschritt = 10;
    int timesToWorkOnData = 3;
    unsigned long memorySizeInBytes = 3000000000; // 3gb


    for (unsigned int i = 0; i < argc; i++) {
        //std::cout << argv[i] << std::endl;
        if (!strcmp(argv[i], "-h")) {
            std::cout<< "Helppage for Ramusinator:\n\nusage:\nRamusinator [options]\n\noptions:\n-s (Ram amount to use in Megabyte) \n-a (times to write to Ram)\n";
            return 0;
        }
        if (argc > 2) {
            if (!strcmp(argv[i], "-s")) {
                memorySizeInBytes = std::atol(argv[i + 1])*1000000;
            }
            if (!strcmp(argv[i], "-a")) {
                timesToWorkOnData = std::atoi(argv[i + 1]);
            }
        }
    }


    if (argc > 3 && argv[1] == "-r") {
        memorySizeInBytes = std::atoi(argv[3]);
    }

    std::cout << "Das Programm wird nun " << memorySizeInBytes << " byte ["
              << static_cast<float>(memorySizeInBytes) / 1000000000 << "Gb] verbrauchen und "
              << timesToWorkOnData << " mal in den Speicher schreiben\n";
    std::byte *data = new std::byte[memorySizeInBytes];

    for (unsigned long i = 0; i < (memorySizeInBytes * timesToWorkOnData); i++) {
        data[i % memorySizeInBytes] = static_cast<std::byte>(i % 255);
        if (0 < (static_cast<long>(static_cast<float>(i * 100) / (memorySizeInBytes * timesToWorkOnData))) &&
            !(static_cast<long>(static_cast<float>(i * 100) / (memorySizeInBytes * timesToWorkOnData)) % fortschritt)) {
            std::cout << fortschritt << "% abgeschlossen.\n";
            fortschritt += 10;
        }
    }
    delete data;
    return 0;
}