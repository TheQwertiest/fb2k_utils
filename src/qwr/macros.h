#pragma once

#define QWR_EXPAND( x ) \
    x
#define QWR_GET_MACRO( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, NAME, ... ) \
    NAME
#define QWR_PASTE( ... ) \
    QWR_EXPAND(          \
        QWR_GET_MACRO(   \
            __VA_ARGS__, \
            QWR_PASTE64, \
            QWR_PASTE63, \
            QWR_PASTE62, \
            QWR_PASTE61, \
            QWR_PASTE60, \
            QWR_PASTE59, \
            QWR_PASTE58, \
            QWR_PASTE57, \
            QWR_PASTE56, \
            QWR_PASTE55, \
            QWR_PASTE54, \
            QWR_PASTE53, \
            QWR_PASTE52, \
            QWR_PASTE51, \
            QWR_PASTE50, \
            QWR_PASTE49, \
            QWR_PASTE48, \
            QWR_PASTE47, \
            QWR_PASTE46, \
            QWR_PASTE45, \
            QWR_PASTE44, \
            QWR_PASTE43, \
            QWR_PASTE42, \
            QWR_PASTE41, \
            QWR_PASTE40, \
            QWR_PASTE39, \
            QWR_PASTE38, \
            QWR_PASTE37, \
            QWR_PASTE36, \
            QWR_PASTE35, \
            QWR_PASTE34, \
            QWR_PASTE33, \
            QWR_PASTE32, \
            QWR_PASTE31, \
            QWR_PASTE30, \
            QWR_PASTE29, \
            QWR_PASTE28, \
            QWR_PASTE27, \
            QWR_PASTE26, \
            QWR_PASTE25, \
            QWR_PASTE24, \
            QWR_PASTE23, \
            QWR_PASTE22, \
            QWR_PASTE21, \
            QWR_PASTE20, \
            QWR_PASTE19, \
            QWR_PASTE18, \
            QWR_PASTE17, \
            QWR_PASTE16, \
            QWR_PASTE15, \
            QWR_PASTE14, \
            QWR_PASTE13, \
            QWR_PASTE12, \
            QWR_PASTE11, \
            QWR_PASTE10, \
            QWR_PASTE9,  \
            QWR_PASTE8,  \
            QWR_PASTE7,  \
            QWR_PASTE6,  \
            QWR_PASTE5,  \
            QWR_PASTE4,  \
            QWR_PASTE3,  \
            QWR_PASTE2,  \
            QWR_PASTE1 )( __VA_ARGS__ ) )
#define QWR_PASTE2( func, v1 ) func( v1 )
#define QWR_PASTE3( func, v1, v2 ) \
    QWR_PASTE2( func, v1 )         \
    QWR_PASTE2( func, v2 )
#define QWR_PASTE4( func, v1, v2, v3 ) \
    QWR_PASTE2( func, v1 )             \
    QWR_PASTE3( func, v2, v3 )
#define QWR_PASTE5( func, v1, v2, v3, v4 ) \
    QWR_PASTE2( func, v1 )                 \
    QWR_PASTE4( func, v2, v3, v4 )
#define QWR_PASTE6( func, v1, v2, v3, v4, v5 ) \
    QWR_PASTE2( func, v1 )                     \
    QWR_PASTE5( func, v2, v3, v4, v5 )
#define QWR_PASTE7( func, v1, v2, v3, v4, v5, v6 ) \
    QWR_PASTE2( func, v1 )                         \
    QWR_PASTE6( func, v2, v3, v4, v5, v6 )
#define QWR_PASTE8( func, v1, v2, v3, v4, v5, v6, v7 ) \
    QWR_PASTE2( func, v1 )                             \
    QWR_PASTE7( func, v2, v3, v4, v5, v6, v7 )
#define QWR_PASTE9( func, v1, v2, v3, v4, v5, v6, v7, v8 ) \
    QWR_PASTE2( func, v1 )                                 \
    QWR_PASTE8( func, v2, v3, v4, v5, v6, v7, v8 )
#define QWR_PASTE10( func, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) \
    QWR_PASTE2( func, v1 )                                      \
    QWR_PASTE9( func, v2, v3, v4, v5, v6, v7, v8, v9 )
#define QWR_PASTE11( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) \
    QWR_PASTE2( func, v1 )                                           \
    QWR_PASTE10( func, v2, v3, v4, v5, v6, v7, v8, v9, v10 )
#define QWR_PASTE12( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) \
    QWR_PASTE2( func, v1 )                                                \
    QWR_PASTE11( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 )
#define QWR_PASTE13( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12 ) \
    QWR_PASTE2( func, v1 )                                                     \
    QWR_PASTE12( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12 )
#define QWR_PASTE14( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13 ) \
    QWR_PASTE2( func, v1 )                                                          \
    QWR_PASTE13( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13 )
#define QWR_PASTE15( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14 ) \
    QWR_PASTE2( func, v1 )                                                               \
    QWR_PASTE14( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14 )
#define QWR_PASTE16( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15 ) \
    QWR_PASTE2( func, v1 )                                                                    \
    QWR_PASTE15( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15 )
#define QWR_PASTE17( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16 ) \
    QWR_PASTE2( func, v1 )                                                                         \
    QWR_PASTE16( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16 )
#define QWR_PASTE18( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17 ) \
    QWR_PASTE2( func, v1 )                                                                              \
    QWR_PASTE17( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17 )
#define QWR_PASTE19( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18 ) \
    QWR_PASTE2( func, v1 )                                                                                   \
    QWR_PASTE18( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18 )
#define QWR_PASTE20( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19 ) \
    QWR_PASTE2( func, v1 )                                                                                        \
    QWR_PASTE19( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19 )
#define QWR_PASTE21( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20 ) \
    QWR_PASTE2( func, v1 )                                                                                             \
    QWR_PASTE20( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20 )
#define QWR_PASTE22( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21 ) \
    QWR_PASTE2( func, v1 )                                                                                                  \
    QWR_PASTE21( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21 )
#define QWR_PASTE23( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22 ) \
    QWR_PASTE2( func, v1 )                                                                                                       \
    QWR_PASTE22( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22 )
#define QWR_PASTE24( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23 ) \
    QWR_PASTE2( func, v1 )                                                                                                            \
    QWR_PASTE23( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23 )
#define QWR_PASTE25( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24 ) \
    QWR_PASTE2( func, v1 )                                                                                                                 \
    QWR_PASTE24( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24 )
#define QWR_PASTE26( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25 ) \
    QWR_PASTE2( func, v1 )                                                                                                                      \
    QWR_PASTE25( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25 )
#define QWR_PASTE27( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26 ) \
    QWR_PASTE2( func, v1 )                                                                                                                           \
    QWR_PASTE26( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26 )
#define QWR_PASTE28( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                \
    QWR_PASTE27( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27 )
#define QWR_PASTE29( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                     \
    QWR_PASTE28( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28 )
#define QWR_PASTE30( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                          \
    QWR_PASTE29( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29 )
#define QWR_PASTE31( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                               \
    QWR_PASTE30( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30 )
#define QWR_PASTE32( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                    \
    QWR_PASTE31( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31 )
#define QWR_PASTE33( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                         \
    QWR_PASTE32( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32 )
#define QWR_PASTE34( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                              \
    QWR_PASTE33( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33 )
#define QWR_PASTE35( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                   \
    QWR_PASTE34( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34 )
#define QWR_PASTE36( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                        \
    QWR_PASTE35( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35 )
#define QWR_PASTE37( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                             \
    QWR_PASTE36( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36 )
#define QWR_PASTE38( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                  \
    QWR_PASTE37( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37 )
#define QWR_PASTE39( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                       \
    QWR_PASTE38( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38 )
#define QWR_PASTE40( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                            \
    QWR_PASTE39( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39 )
#define QWR_PASTE41( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                 \
    QWR_PASTE40( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40 )
#define QWR_PASTE42( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                      \
    QWR_PASTE41( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41 )
#define QWR_PASTE43( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                           \
    QWR_PASTE42( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42 )
#define QWR_PASTE44( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                \
    QWR_PASTE43( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43 )
#define QWR_PASTE45( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                     \
    QWR_PASTE44( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44 )
#define QWR_PASTE46( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                          \
    QWR_PASTE45( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45 )
#define QWR_PASTE47( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                               \
    QWR_PASTE46( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46 )
#define QWR_PASTE48( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                    \
    QWR_PASTE47( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47 )
#define QWR_PASTE49( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                         \
    QWR_PASTE48( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48 )
#define QWR_PASTE50( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                              \
    QWR_PASTE49( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49 )
#define QWR_PASTE51( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                   \
    QWR_PASTE50( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50 )
#define QWR_PASTE52( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                        \
    QWR_PASTE51( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51 )
#define QWR_PASTE53( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                             \
    QWR_PASTE52( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52 )
#define QWR_PASTE54( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                  \
    QWR_PASTE53( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53 )
#define QWR_PASTE55( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                       \
    QWR_PASTE54( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54 )
#define QWR_PASTE56( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                            \
    QWR_PASTE55( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55 )
#define QWR_PASTE57( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                                 \
    QWR_PASTE56( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56 )
#define QWR_PASTE58( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                                      \
    QWR_PASTE57( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57 )
#define QWR_PASTE59( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                                           \
    QWR_PASTE58( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58 )
#define QWR_PASTE60( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                                                \
    QWR_PASTE59( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59 )
#define QWR_PASTE61( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                                                     \
    QWR_PASTE60( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60 )
#define QWR_PASTE62( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                                                          \
    QWR_PASTE61( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61 )
#define QWR_PASTE63( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                                                               \
    QWR_PASTE62( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62 )
#define QWR_PASTE64( func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63 ) \
    QWR_PASTE2( func, v1 )                                                                                                                                                                                                                                                                                                                    \
    QWR_PASTE63( func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63 )
