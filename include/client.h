#ifndef CLIENT_H
#define CLIENT_H

struct Client
{
    int wallet{}; // Money in client's wallet

    /**
     * @brief Return true if client's wallet is valid.
     *
     * @return boolean.
     */
    [[nodiscard]] bool isWalletValid() const;
};

#endif
