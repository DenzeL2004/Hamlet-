#ifndef _GENERALS_H_
#define _GENERALS_H_

/**
 * @def is_error
 * @brief Checks for false input conditions
 * @note This define does not terminate the program in case of an error like assert
*/
#define is_error(condition) {                                           \
    if (!(condition))                                                   \
        printf ("ERROR in %s in line %d in file %s in function %s\n",   \
                #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__);   \
}

const char RESET[]  =     "\033[0m";     ///< Standart colour
const char RED[]    =  "\033[1;31m";     ///< Red colour
const char BLUE[]   =  "\033[1;36m";     ///< Blue colour
const char GREEN[]  =  "\033[1;32m";     ///< Green colour
const char YELLOW[] =  "\033[1;33m";     ///< Yellow colour

const long double Eps = 1e-10; ///< Global constant equal to \f$\ 10^{-9}\f$

/**
 * @enum Errors
 * @brief Represents the status of errors
*/
enum Errors {
    ERR_MEMORY_ALLOC = -1,          ///< Memory is not allocated
    ERR_INIT_BUF     = -2,          ///< Buffer has not been initialized
    ERR_FILE_READING = -3,          ///< No data was read from the file
    ERR_INIT_LINES   = -4,          ///< Strings not initialized
    ERR_TEXT_READING = -5,          ///< Text not initialized
    ERR_FILE_OPEN    = -6,          ///< File is not open
    ERR_WRITING      = -7           ///< Data writing failed
};

/**
 * @struct Flags
 * @brief Represents the status of flags
*/
struct Options{
    bool Read_on_file   = 0;
    bool Write_on_file = 0;
};


/** 
 * @brief Comparison of double variables
 * @version 1.0.0
 * @param [in] num1 input double parameter
 * @param [in] num2 input double parameter
 * @return False - number is not equal, true - number is equal
*/
bool Equality_double (double num1, double num2);

/** 
 * @brief Comparing a number to zero
 * @version 1.0.0
 * @param [in] n input parameter
 * @return False - number is not zero, true - number is zero
*/
bool Is_zero (double num);

/** 
 * @brief Correct zero value
 * @version 1.0.0
 * @param [in] n input parameter
 * @note If the value is zero the program must not return -0.00
 * @return Returns zero if the number is zero, otherwise returns the number itself
*/
double Fix_zero (double num);

/** 
 * @brief Paints a line
 * @version 1.0.0
 * @param [in] colour colour you want to paint a string
 * @param [in] str line to be colored
*/
void Print_colour (char const colour[], char const *str, ...);

/** 
 * @brief Paints a line
 * @version 1.0.0
 * @param [in] argc argument count
 * @param [in] argv argument values
*/
int Parsing (int argc, char *argv[], Options *flags);

/**
 * @brief 
 *  
 * @param [in] name_file Name of file 
 * @param [in] mode Open file access modes
 * @return Pointer on file 
 */
FILE *Open_file (const char *name_file, const char *mode);

/**
 * @brief Swaps the values of variables
 * 
 * @param obj1 [in] first variable
 * @param obj2 [in] second variable
 * @param size_type [in] size of variables in bytes
 * @return Returns zero if the variables have changed values 
 */
int My_swap (void *obj1, void *obj2, size_t size_type);

#endif