#ifndef ACCOUNT_H
#define ACCOUNT_H

/**
 * @brief Client account.
 */
struct Account
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
