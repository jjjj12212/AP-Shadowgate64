import hashlib
import os
import bsdiff4

def read_file(path):
        with open(path, 'rb') as fi:
            data = fi.read()
        return data

bsdiff4.file_diff("Shadowgate64.z64", "ShadowPatch.n64", "Randogate64.patch")
if os.path.isfile("ShadowPatch.n64"):
    rom = read_file("ShadowPatch.n64")
print(hashlib.md5(rom).hexdigest())


