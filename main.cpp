#include "vector.cpp"

int main()
{
    // BATCH TESTING WITH DIFFERENT TYPES... (manual testing)

    Vector<int> copyMe = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Vector<int> v = copyMe;
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);

    //  Printing the vector
    std::cout << "front: " << v.front()
              << "\nback: " << v.back()
              << "\nsize: " << v.size()
              << "\ncapacity: " << v.capacity() << std::endl;

    // Thanks to our member iterator, we can iterate through the vector
    for (const auto &i : v)
        std::cout << i << ", ";

    v.pop_back();
    std::cout << "\nPOPPED:" << std::endl;

    std::cout << "front: " << v.front()
              << "\nback: " << v.back()
              << "\nsize: " << v.size()
              << "\ncapacity: " << v.capacity() << std::endl;

    for (const auto &i : v)
        std::cout << i << ", ";

    v.erase(v.begin() + 6, v.end());
    std::cout << "\nERASED:" << std::endl;

    std::cout << "front: " << v.front()
              << "\nback: " << v.back()
              << "\nsize: " << v.size()
              << "\ncapacity: " << v.capacity() << std::endl;

    for (const auto &i : v)
        std::cout << i << ", ";

    v.shrink_to_fit();
    std::cout << "\nSHRUNK:" << std::endl;

    std::cout << "front: " << v.front()
              << "\nback: " << v.back()
              << "\nsize: " << v.size()
              << "\ncapacity: " << v.capacity() << std::endl;

    for (const auto &i : v)
        std::cout << i << ", ";

    return 0;
}