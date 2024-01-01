def num_decodings(message):
    if not message:
        return 0

    n = len(message)
    # dp[i] mesajın ilk i karakteri için kaç farklı çözüm olduğunu saklar
    dp = [0] * (n + 1)
    dp[0] = 1  # Boş mesaj tek bir çözüme sahiptir

    for i in range(1, n + 1):
        # Tek haneli sayıyı kontrol et
        if 1 <= int(message[i - 1]) <= 9:
            dp[i] += dp[i - 1]

        # İki haneli sayıyı kontrol et
        if i > 1 and 10 <= int(message[i - 2:i]) <= 26:
            dp[i] += dp[i - 2]

    return dp[n]

# Örnek kullanım
encoded_message = "1111"
result = num_decodings(encoded_message)
print(f"The number of ways to decode '{encoded_message}' is: {result}")
