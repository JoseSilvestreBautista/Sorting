#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <ctime>
#include <chrono>

/** Merges the arrays created from mergeSort().
 * */
void merge(int array[], int begin, int middle, int end) {

    int leftSize = middle - begin + 1;
    int rightSize = end - middle;

    int left[leftSize];
    int right[rightSize];

    for (int i = 0; i < leftSize; i++)
        left[i] = array[begin + i];
    for (int j = 0; j < rightSize; j++)
        right[j] = array[middle + 1 + j];

    int i = 0; // left array index
    int j = 0; // right array index
    int k = begin; // array index
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        array[k] = left[i];
        i++;
        k++;
    }


    while (j < rightSize) {
        array[k] = right[j];
        j++;
        k++;
    }
}

/** Recursively calls mergeSort() split array in half.
 * */
void mergeSort(int array[], int begin, int end) {
    if (begin < end) {

        int middle = begin + (end - begin) / 2;
        mergeSort(array, begin, middle);
        mergeSort(array, middle + 1, end);
        merge(array, begin, middle, end);
    }
}

/** Compares one element with another until the array is sorted.
 * */
void insertionSort(int array[], int arraySize) {
    int left, right;

    for (int i = 0; i < arraySize - 1; i++) {
        left = array[i];
        right = array[i + 1];

        while (left > right) {
            array[i] = right;
            array[i + 1] = left;
            i != 0 ? i = i - 1 : i = i;
            left = array[i];
        }
    }
}

/** Reads text files sorted, random, and reverse sorted txt files.
 * */
void readFromFile(int array[], const std::string &txt) {

    std::string line;
    std::ifstream myfile(txt);
    int index = 0;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            int data = stoi(line);
            array[index] = data;
            index++;
        }
        myfile.close();
    } else std::cout << "Unable to open file";

}

/** Reads a sorted txt file and reverse it.
 * i.e ascending to descending order
 * */
void reverseReadFromFile(int array[], int arraySize, const std::string &txt) {

    std::string line;
    std::ifstream myfile(txt);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            int data = stoi(line);
            array[arraySize - 1] = data;
            arraySize--;
        }
        myfile.close();
    } else std::cout << "Unable to open file";

}

/**Copies the elements in the array into a txt file.
 * */
void writeToFile(int array[], int arraySize, std::string txtOutput) {
    std::ofstream myfile;
    myfile.open(txtOutput, std::ios::trunc);
    int data[arraySize];
    for (int i = 0; i < arraySize; i++) {
        data[i] = array[i];
        myfile << data[i] << std::endl;
    }
    myfile.close();

}

/** generates random number with a range i.e (starting number, ending number).
 * Is a repetitive generator.
 * */
void generateRandomNumber(int array[], int count) {

    std::uniform_int_distribution<int> d(0, 1e7);
    std::random_device rd1; // uses RDRND or /dev/urandom
    for (int n = 0; n < count; n++)
        array[n] = d(rd1);
}

/** Prints an array given the size of the array.
 * */
void printArray(int array[], int arraySize) {
    int i;
    for (i = 0; i < arraySize; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main() {
    // Random keys are stores in txtInput
    std::string txtInput[] = {"10.keys.txt", "100.keys.txt", "1000.keys.txt", "10000.keys.txt", "100000.keys.txt"};
    std::string txtOutputInsertion[] = {"output.insertionSort.10.keys.txt", "output.insertionSort.100.keys.txt",
                                        "output.insertionSort.1000.keys.txt", "output.insertionSort.10000.keys.txt",
                                        "output.insertionSort.100000.keys.txt"};
    //Sorted values
    std::string txtOutputInsertionDescending[] = {"output.insertionSort.descending .10.keys.txt",
                                                  "output.insertionSort.descending .100.keys.txt",
                                                  "output.insertionSort.descending .1000.keys.txt",
                                                  "output.insertionSort.descending .10000.keys.txt",
                                                  "output.insertionSort.descending .100000.keys.txt"};
    //Sorted values
    std::string txtOutputInsertionAscending[] = {"output.insertionSort.ascending.10.keys.txt",
                                                 "output.insertionSort.ascending.100.keys.txt",
                                                 "output.insertionSort.ascending.1000.keys.txt",
                                                 "output.insertionSort.ascending.10000.keys.txt",
                                                 "output.insertionSort.ascending.100000.keys.txt"};
    //sorted values
    std::string txtOutputMerge[] = {"output.mergeSort.10.keys.txt", "output.mergeSort.100.keys.txt",
                                    "output.mergeSort.1000.keys.txt", "output.mergeSort.10000.keys.txt",
                                    "output.mergeSort.100000.keys.txt"};
    //sorted values

    std::string txtOutputMergeDescending[] = {"output.mergeSort.descending .10.keys.txt",
                                              "output.mergeSort.descending .100.keys.txt",
                                              "output.mergeSort.descending .1000.keys.txt",
                                              "output.mergeSort.descending .10000.keys.txt",
                                              "output.mergeSort.descending .100000.keys.txt"};
    //sorted values
    std::string txtOutputMergeAscending[] = {"output.mergeSort.Ascending.10.keys.txt",
                                             "output.mergeSort.Ascending.100.keys.txt",
                                             "output.mergeSort.Ascending.1000.keys.txt",
                                             "output.mergeSort.Ascending.10000.keys.txt",
                                             "output.mergeSort.Ascending.100000.keys.txt"};
    int count = 10;
    int txtCount = 0;
    /**
     * populates the input file with random numbers from random number generator
     * **/
    do {
        txtInput[txtCount];
        int array[count];
        generateRandomNumber(array, count);
        writeToFile(array, count, txtInput[txtCount]);
        count *= 10;
        txtCount++;
    } while (count < 100001);

    count = 10;
    txtCount = 0;

    /**
     * Invokes insertionSort() for random Keys.
     * **/
    do {
        int array[count];
        readFromFile(array, txtInput[txtCount]);
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(array, count);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout << "insertion sort for random " << count << " keys is " << microseconds << " microseconds"
                  << std::endl;
        writeToFile(array, count, txtOutputInsertion[txtCount]);
        count *= 10;
        txtCount++;
    } while (count < 100001);

    std::cout << " " << std::endl;
    count = 10;
    txtCount = 0;
    /**
   * invokes insertionSort() for descending order of keys.
   * **/
    do {
        int array[count];
        reverseReadFromFile(array, count, txtOutputInsertion[txtCount]);
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(array, count);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout << "insertion sort for descending " << count << " keys is " << microseconds << " microseconds"
                  << std::endl;
        writeToFile(array, count, txtOutputInsertionDescending[txtCount]);
        count *= 10;
        txtCount++;
    } while (count < 100001);

    std::cout << " " << std::endl;
    count = 10;
    txtCount = 0;
    /**
 * Invokes insertionSort() for ascending order of keys.
 * **/
    do {
        int array[count];
        readFromFile(array, txtOutputInsertion[txtCount]);
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(array, count);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout << "insertion sort for ascending " << count << " keys is " << microseconds << " microseconds"
                  << std::endl;
        writeToFile(array, count, txtOutputInsertionAscending[txtCount]);
        count *= 10;
        txtCount++;
    } while (count < 100001);

    std::cout << " " << std::endl;
    count = 10;
    txtCount = 0;

    /**
 * Invokes mergeSort() for random order of keys.
 * **/
    do {
        int array[count];
        readFromFile(array, txtInput[txtCount]);
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(array, 0, count - 1);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout << "merge sort for random " << count << " keys is " << microseconds << " microseconds" << std::endl;
        writeToFile(array, count, txtOutputMerge[txtCount]);
        count *= 10;
        txtCount++;
    } while (count < 100001);

    std::cout << " " << std::endl;
    count = 10;
    txtCount = 0;
    /**
* Invokes mergeSort() for descending order of keys.
* **/
    do {
        int array[count];
        reverseReadFromFile(array, count, txtOutputMerge[txtCount]);
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(array, 0, count - 1);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout << "merge sort for descending " << count << " keys is " << microseconds << " microseconds"
                  << std::endl;
        writeToFile(array, count, txtOutputMergeDescending[txtCount]);
        count *= 10;
        txtCount++;
    } while (count < 100001);

    std::cout << " " << std::endl;
    count = 10;
    txtCount = 0;
    /**
* Invokes mergeSort() for ascending order of keys.
* **/
    do {
        int array[count];
        readFromFile(array, txtOutputMerge[txtCount]);
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(array, 0, count - 1);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout << "merge sort for ascending " << count << " keys is " << microseconds << " microseconds"
                  << std::endl;
        writeToFile(array, count, txtOutputMergeAscending[txtCount]);
        count *= 10;
        txtCount++;
    } while (count < 100001);

    return 0;

}

//clock_t time_req;
//time_req = clock();
//time_req = clock() - time_req;
//std::cout << "Using pow function, it took " << (float) time_req / CLOCKS_PER_SEC << " seconds" << std::endl;

