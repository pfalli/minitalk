# minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.

- Requirements

    You must create a communication program in the form of a client and a server.

        1. The server must be started first. After its launch, it has to print its PID.
        2. The client takes two parameters: 1) The server PID 2) The string to send.
        3. The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
        4. The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
        5. Your server should be able to receive strings from several clients in a row without needing to restart.
        6. The communication between your client and your server has to be done only using UNIX signals.
        7. You can only use these two signals: SIGUSR1 and SIGUSR2.


