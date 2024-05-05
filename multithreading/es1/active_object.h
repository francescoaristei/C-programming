# ifndef ACTIVEOBJECT
# define ACTIVEOBJECT

# include <atomic>
# include <thread>

using namespace std;

class ActiveObject {
    public:
        ActiveObject ();
        virtual ~ActiveObject ();
    private:
        virtual void run ();
        ActiveObject (const ActiveObject&) = delete;
        ActiveObject& operator=(const ActiveObject&) = delete;
    protected: 
        thread t;
        atomic<bool> quit;
};
# endif