def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(pair):
    def get_first_element(a, b):
        return a
    return pair(get_first_element)

def cdr(pair):
    def get_last_element(a, b):
        return b
    return pair(get_last_element)

my_pair = cons(3, 4)
print("car:", car(my_pair))  # Çıktı: 3
print("cdr:", cdr(my_pair))  # Çıktı: 4
