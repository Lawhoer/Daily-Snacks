def climb_stairs_with_set(n, steps):
    if n == 0:
        return 1

    ways = [0] * (n + 1)
    ways[0] = 1

    for i in range(1, n + 1):
        for step in steps:
            if i - step >= 0:
                ways[i] += ways[i - step]

    return ways[n]

# Örnek olarak, N = 4 ve X = {1, 2} için
result = climb_stairs_with_set(4, {1, 2})
print(f"4 adımlık merdiveni tırmanmanın {result} farklı yolu vardır.")
