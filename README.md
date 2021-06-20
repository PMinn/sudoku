# sudoku

## 分工

- 黃緒誠  ->  資料查找 , main流程設計
- 林廷翌  ->  物件設計 , 數獨基本函式編寫 , 視覺化頁面設計
- 潘子珉  ->  效能優化 , 遊戲體驗優化 , 程式除錯校正

## 此小專題使用
```
物件(包括data field、constructor、function、private)
封裝
只准許輸入方向及數字鍵達到防呆
callback function(用於數獨版面載入中的遊戲介面)
非同步處理(數獨確認唯一解使用遞迴函式較耗時，非同步用於遊玩過程中可同時載入新的數獨版面，確保遊戲順暢)
```

## 遊戲介紹
### 規則
<img src="https://github.panalan.repl.co/sudoku/00.png" width="500" >

``
遊戲規則
按任意鍵後開始遊戲
``

### 移動
<img src="https://github.panalan.repl.co/sudoku/1.gif" width="500">

``
使用方向鍵移動控制
``

### 輸入與次數
<img src="https://github.panalan.repl.co/sudoku/2.gif" width="500">

``
按下數字鍵輸入
每局只有5次的錯誤機會
次數歸零即挑戰失敗
``

### 結束與重新
<img src="https://github.panalan.repl.co/sudoku/3.gif" width="500">

``
最後遊戲結束後
不管輸贏會載入接著下一局
``
