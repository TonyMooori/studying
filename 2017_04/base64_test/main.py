#conding:uft-8

import base64

# ipython notebookから引っ張ってきたpng画像をbase64形式で保存したデータ
with open("./pngdata.txt","r") as f:
    png_base64 = f.readlines()

png_base64 = "".join(png_base64)
print(png_base64)

dec_file = base64.b64decode( png_base64 )

with open('./output.png', 'wb') as f:
    f.write(dec_file)
