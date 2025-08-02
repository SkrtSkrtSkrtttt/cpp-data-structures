//Naafiul Hossain
//SBU ID: 115107623

//I did this all in one main class due to having trouble linlking classes here on VSCODE 

#include <iostream>
#include <vector>
#include <algorithm>

class CustomContainer;

class CustomIterator {
public:
    CustomIterator(CustomContainer* container, int index) : container(container), index(index) {}

    CustomIterator begin();
    CustomIterator end();
    int operator*();
    void operator++();
    bool operator!=(const CustomIterator& other) const;

private:
    CustomContainer* container;
    int index;
};

class CustomContainer {
public:
    void add(int value) {
        elements.push_back(value);
    }

    int size() const {
        return elements.size();
    }

    int get(int index) const {
        if (index >= 0 && index < elements.size()) {
            return elements[index];
        }
        else {
            // Handle index out of bounds error
            return -1; //  test
            //return 0
        }
    }

    void remove(int value) {
        elements.erase(std::remove(elements.begin(), elements.end(), value), elements.end());
    }

    CustomIterator begin() {
        return CustomIterator(this, 0);
    }

    CustomIterator end() {
        return CustomIterator(this, size());
    }

private:
    std::vector<int> elements;
};

CustomIterator CustomIterator::begin() {
    return CustomIterator(container, 0);
}

CustomIterator CustomIterator::end() {
    return CustomIterator(container, container->size());
}

int CustomIterator::operator*() {
    return container->get(index);
}

void CustomIterator::operator++() {
    index++;
}

bool CustomIterator::operator!=(const CustomIterator& other) const {
    return index != other.index;
}

int main() {
    CustomContainer container;

    // Add elements to the container
    container.add(1);
    container.add(2);
    container.add(3);
    container.add(2);
    container.add(4);

    // Remove occurrences of the value 2
    container.remove(2);

    // Print the elements using the iterator
    std::cout << "Container Elements: ";
    for (CustomIterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    return 0;
}
