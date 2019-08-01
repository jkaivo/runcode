# runcode

execute raw binary code from a file

# Synopsis

`runcode file`

# Description

The `runcode` utility loads an arbitrary binary file into memory and attempts
to execute it. This is useful for testing shellcode used in penetration
testing.

# Options

None.

# Operands

`file` A file containing executable instructions.

# STDIN

Not used by `runcode` itself. May be used by the loaded program.

# Input Files

The input file must be contain valid executable instructions appropriate
to architecture `runcode` is being executed on.

# STDOUT

Not used by `runcode` itself. May be used by the loaded program.

# STDERR

Used for diagnostic messages.

# Output Files

None.

# Extended Description

None.

# Exit Status

0	Successful completion.
>0	An error occurred.

# Consequence of Errors

If the file specified cannot be opened for reading or mapped for execution,
a diagnostic message will be printed to standard error. Behavior is undefined
if the file specified does not contain an executable instruction at its first
byte.

