typedef struct rsb_infinitesimal rsb_infinitesimal;
typedef struct rsb_scalar rsb_scalar;
typedef struct rsb_matrix rsb_matrix;
typedef struct rsb_value rsb_value;
typedef struct rsb_operation rsb_operation;
typedef struct rsb_function rsb_function;

/******************************************************************************/

typedef double rsb_real;
typedef unsigned int rsb_symbol;

typedef enum
{
    RSB_SYMBOL,
    RSB_REAL,
    RSB_INFINITESIMAL
} rsb_scalar_type;

typedef enum
{
    RSB_SCALAR,
    RSB_MATRIX
} rsb_value_type;

typedef enum
{
    RSB_ADDITION,
    RSB_SUBTRACTION,
    RSB_MULTIPLICATION,
    RSB_DIVISION,
    
    RSB_EXPONENT,
    RSB_ROOT,
    RSB_LOGARITHM,
    
    RSB_SUMMATION,
    RSB_PRODUCT,
    
    RSB_LIMIT,
    RSB_DERIVATIVE,
    
    RSB_EQUALS,
    RSB_NOTEQUALS,
    RSB_LESSTHAN,
    RSB_GREATERTHAN,
    RSB_LESSTHANOREQUAL,
    RSB_GREATERTHANOREQUAL
} rsb_operation_type;

/******************************************************************************/

struct rsb_infinitesimal
{
    rsb_symbol upper;
    rsb_symbol lower;
};

struct rsb_scalar
{
    rsb_scalar_type type;
    union
    {
        rsb_real          real;
        rsb_symbol        symbol;
        rsb_infinitesimal infinitesimal;
    } value;
};

struct rsb_matrix
{
    unsigned int dimensions;
    unsigned int* widths;
    rsb_scalar* values;
};

struct rsb_value
{
    rsb_value_type type;
    union
    {
        rsb_scalar scalar;
        rsb_matrix matrix;
    } value;
};

struct rsb_operation
{
    rsb_operation_type type;
    rsb_value* arguments;
};

struct rsb_function
{
    rsb_operation* operation;
    unsigned int constraint_count;
    rsb_operation* constraints;
};

static const struct
{
    rsb_operation_type type;
    unsigned int min;
    unsigned int max;
} RSB_OPARG_COUNTS[] = { { RSB_ADDITION          , 2, 2 },
                         { RSB_SUBTRACTION       , 2, 2 },
                         { RSB_MULTIPLICATION    , 2, 2 },
                         { RSB_DIVISION          , 2, 2 },
                         
                         { RSB_EXPONENT          , 2, 2 },
                         { RSB_ROOT              , 2, 2 },
                         { RSB_LOGARITHM         , 2, 2 },
                         
                         { RSB_SUMMATION         , 3, 3 },
                         { RSB_PRODUCT           , 3, 3 },
                         
                         { RSB_LIMIT             , 3, 3 },
                         { RSB_DERIVATIVE        , 2, 2 },
                         
                         { RSB_EQUALS            , 2, 2 },
                         { RSB_NOTEQUALS         , 2, 2 },
                         { RSB_LESSTHAN          , 2, 2 },
                         { RSB_GREATERTHAN       , 2, 2 },
                         { RSB_LESSTHANOREQUAL   , 2, 2 },
                         { RSB_GREATERTHANOREQUAL, 2, 2 } };
