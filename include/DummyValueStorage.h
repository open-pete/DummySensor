/**
 * DummyValueStorage.h
 * Purpose: defines class DummyValueStorage
 *
 * @author mezorian
 * @version 1.1.0
 */

#ifndef DummyValueStorage_H
#define DummyValueStorage_H

#include "CompileTimeOptions.h"

#ifdef DUMMY_VALUES

    #include <map>
    #include <string>

    #include "HRand.h"

    /**
     * DummyValueStorage class
     * @brief DummyValueStorage stores global variables for dummy-value generation in singleton-class
     *
     */
    class DummyValueStorage {
        public:
            /* --- needed to create a singleton --- */
            static DummyValueStorage& getInstance() {
                static DummyValueStorage _instance;
                return _instance;
            }
            ~DummyValueStorage() {}

            /* --- dummy values storage --- */
            std::map<std::string,HRand> values;
    };

#endif DUMMY_VALUES

#endif // DummyValueStorage_H

