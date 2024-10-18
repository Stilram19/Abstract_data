#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

namespace ft {
    template <typename T>
    class vector {
        // types aliases
        private:
            typedef T value_type;
            typedef std::allocator<T> allocator_type;
            typedef allocator_type::reference reference;
            typedef allocator_type::const_reference const_reference;
            typedef allocator_type::pointer pointer;
            typedef allocator_type::const_pointer const_pointer;
            typedef size_t  size_type;

        // attributes
        private:
            size_type       _size;
            size_type       _capacity;
            pointer         _data;
            allocator_type  _alloc;

        // constructors & destructor & assignment
        public:
            // default constructor (using the explicit keyword to make code using the vector class clearer)
            explicit vector(const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _data(NULL), _alloc(alloc) {}

            // fill constructor
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), _data(NULL), _alloc(alloc) {
                this->_data = this->_alloc.allocate(n);

                for (size_type i = 0; i < n; i++) {
                    this->_alloc.construct(this->_data + i, val);
                }
            }

            // range constructor
            template <class InputIterator> vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {}

            // copy constructor
            vector(const vector& x) {
                *this = x; // rely on the assignment
            }

            // copy assignment
            vector& operator= (const vector& x) {
                if (*this == x) {
                    return (*this);
                }

                // destroy all elements and release currently allocated memory
                this->cleanup();

                this->_size = x._size;
                this->_capacity = x._capacity;

                // allocate new memory
                this->_data = this->_alloc.allocate(this->_capacity);

                // construct new allocated memory with x's elements copies
                for (size_type i = 0; i < this->_size; i++) {
                    this->_alloc.construct(this->_data + i);
                }
            }

            // destructor
            ~vector() {
               this->cleanup();
            }

        // helpers
        private:

            // @brief calls the destructor of each element in the vector,
            // and releases the current allocated memory for the vector.
            void cleanup() {
                for (size_type i = 0; i < this->_size; i++) {
                    this->_alloc.destroy(this->_data + i);
                }

                this->_alloc.deallocate(this->_data, this->_capacity);
            }
    };

};

#endif
