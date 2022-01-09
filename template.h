
template<typename T>
struct Templated {
    Templated(T t) : v{t} {}
    const T& get() const;
    void set(const T& t);
    T v;
};
