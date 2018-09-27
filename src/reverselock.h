// Copyright (c) 2015 The Lkcoinse Core developers
// Copyright (c) 2015-2017 The Lkcoinse Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LKCOINSE_REVERSELOCK_H
#define LKCOINSE_REVERSELOCK_H

/**
 * An RAII-style reverse lock. Unlocks on construction and locks on destruction.
 */
template <typename Lock>
class reverse_lock
{
public:
    explicit reverse_lock(Lock &_lock) : lock(_lock)
    {
        lock.unlock();
        lock.swap(templock);
    }

    ~reverse_lock()
    {
        templock.lock();
        templock.swap(lock);
    }

private:
    reverse_lock(reverse_lock const &);
    reverse_lock &operator=(reverse_lock const &);

    Lock &lock;
    Lock templock;
};

#endif // LKCOINSE_REVERSELOCK_H
