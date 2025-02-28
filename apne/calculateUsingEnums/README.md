# Caluclate with Error codes
Program that uses enums for error codes and maintains output of each operation with proper error codes for each operation
Error codes enum - `enum Error { SUCCESS, DIVISIONBYZERO, INVALIDOPERATION }`

## Error handling
Each operation result object contains an additional error field. If there was some error in calculating the result, the eror field is populated with appropriate error code. Otherwise, the SUCCESS error code is there, marking successful calculation.

The result object has this simple struct definition -
<pre>
    struct Out {
        double res;  // result field
        Error err;   // Error code
    };
</pre>

