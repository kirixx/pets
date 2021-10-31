#pragma once
#include <memory>
#include <iostream>
class Printer
{
public:
    void setWeakValue(std::weak_ptr<int> p)
    {
        std::cout << "Shared pointer to weak pointer\n";
        mWeakPointer = p;
    }

    void setSharedValue(std::shared_ptr<int> p)
    {
        std::cout << "Shared pointer to shared pointer\n";
        mSharedPointer = p;
    }
    
    void printWeakP()
    {
        std::cout << "Weak pointer : \n";
        if (mWeakPointer.expired())
        {
            std::cout << "Resource is no longer available\n";
            return;
        }
        auto sharedp = mWeakPointer.lock();
        std::cout << "value is " << *sharedp << '\n';
        std::cout << "reference count " << sharedp.use_count() << '\n';
    }

    void printSharedP()
    {
        std::cout << "Shared pointer : \n";
        std::cout << "value is " << *mSharedPointer << '\n';
        std::cout << "reference count " << mSharedPointer.use_count() << '\n';
    }

private:
    std::weak_ptr<int> mWeakPointer;
    std::shared_ptr<int> mSharedPointer;
};