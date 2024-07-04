#pragma once

/** INTERFACE_CLASS macro
 * implements some default constructors/destructors intended to be used by simple pure virtual interfaces.
 * @param CLS_NAME The name of this Class.
 */
// NOLINTBEGIN(bugprone-macro-parentheses)
#define INTERFACE_CLASS(CLS_NAME)                       \
public:                                                 \
    CLS_NAME() = default;                               \
    virtual ~CLS_NAME() = default;                      \
                                                        \
    CLS_NAME(CLS_NAME& rhs) = default;                  \
    CLS_NAME& operator=(const CLS_NAME& rhs) = default; \
    CLS_NAME(CLS_NAME&& rhs) = default;                 \
    CLS_NAME& operator=(CLS_NAME&& rhs) = default;
// NOLINTEND(bugprone-macro-parentheses)
