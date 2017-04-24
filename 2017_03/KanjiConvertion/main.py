# coding:utf-8
# http://qiita.com/almichest/items/52f871ee22e4a44346d4

from pykakasi import kakasi
kakasi = kakasi()
kakasi.setMode('H', 'a')
kakasi.setMode('K', 'a')
kakasi.setMode('J', 'a')
conv = kakasi.getConverter()
print(conv.do('本日は晴天なり')) # honjitsuhaseitennari