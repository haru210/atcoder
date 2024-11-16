# コンテストに出る前に
- その入力、sortされてますか  

# RE出た時に見るやつ

配列サイズ確認  
ゼロ徐算確認  

# うまく実行せん時に見るやつ
return 0 の位置あってますか  
cinありますか特に最初のn,mなど
添え字一個ずつ確認しよう  
indexedの確認  
命令が正しいかだけじゃなく順番が正しいかもちゃんと考えよう
# TLE出たときにすること  
つけてみる
```
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
```  
見つかったら探索終了しているか  
mapのアクセス回数減らせないか