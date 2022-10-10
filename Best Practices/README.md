# Best Practices

## Struct

- Use the **struct keyword** for data-only structures. Use the **class keyword** for objects that have both data and functions.

~~~C++

    // Wrong use. Variables actually have operations.
    struct Employee {
        int id {};
        int age {};
        double wage {};
    };

    // True use
    class Employee {
        private:
            int m_id {};
            int m_age {};
            double m_wage {};

        public:
            void print(){
                cout << "Id: " << m_id << " Age: " << m_age << " Wage: " << m_wage << endl;
            }
    };

~~~
