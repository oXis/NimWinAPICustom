import hashes

proc CalcHashSalt*(str: string): int =
    var salt: Hash = 50

    var hash = hash(salt + hash(str))

    return hash