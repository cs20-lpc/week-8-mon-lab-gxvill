template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    // this is the constructor function i think this wants me to create an array stack of length i?
    maxSize = i;
    this->length = 0;
    buffer = new T[i];
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    // done
    // this function is to clear the array stack, but does this also mean to delete it?
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    // done
    // this function is to copy the current array stack to the copy object

    // making buffer a default with length of the argument stack
    if(copyObj.maxSize == 0){
        if(buffer) delete[] buffer;
        buffer = nullptr;
        this->length = 0;
        maxSize = 0;
        return;
    }

    buffer = new T[copyObj.maxSize];


    for(int i = 0; i < copyObj.length; i++){
        buffer[i] = copyObj.buffer[i];
    }
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    // DONE
    // this funciton is to look at the top value of the arraystack

    if(this->length == 0 || buffer == nullptr){
        throw string("Error peek: the stack is empty!");
    }

    return buffer[this->length-1];
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    // this function removes the last item in the array stack

    if(this->length == 0 || !buffer){
        throw string("Error pop: array is empty");
    }
    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    // this functino pushes elem to the back of the stack

    if(this->length == maxSize){
        throw string("Error push: array is full,cannot push");
    }

    buffer[this->length] = elem;
    this->length++;

    
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
    // DONE
    // this function either brings the back elem the front, or the front elem to the back
    
    // top elem goes to bottom
    if(this->length == 0 || this->length == 1){
        return;
    }
    if(dir == Stack<T>::RIGHT){
        T temp = buffer[this->length-1];
        // shift every element to the right
        for(int i = this->length-1; i > 0;i--){
            buffer[i] = buffer[i-1];
        }
        buffer[0] = temp;

    }
    // bottom element goes to top
    else if(dir == Stack<T>::LEFT){
        T temp = buffer[0];
        // shift every element to the left
        for(int i = 0; i < this->length - 1;i++){
            buffer[i] = buffer[i+1];
        }
        buffer[this->length-1] = temp;
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}

