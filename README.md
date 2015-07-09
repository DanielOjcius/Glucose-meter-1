
#Option 設定
>1.SysVolt 3.0V(LCD屏為3V)  
2.OSC: HIRC.Fitler oFF  
3.Low Freq OSC: LIRC  
4.HIRC: 4MHz  
5.WDT Source : Fsub  
6.WDT: By S/W Control  
7.XTAL Mode: 1MHz~12MHz  
8.TMR/INT Pin RC filter: Disable  
9.I2C Debounce Time: No Debounce  
#注意事項
>1.此demo code只做功能演示及設定參考用,不直接作為產品代碼使用,用戶可自行在此版本
  上進行修改以用於產品，但須自行完成嚴格的代碼測試。  
2.common.h包含順序  
  較多文件需要依賴 uerdefine.h 中的定義  
  建議包含順序  
  MCU.h  
  userdefine.h  
  ....  
3.該demo code適用于血糖儀系列MCU音頻通信演示用  
4.使用該demo code前,請在Userdefine.h中按選擇系統頻率,MCU類型(支援HT45F65 &
 HT45F66 & HT45F67)顯示需要調整  
5.若需要使用UART建議使用外部晶振  
6.用戶需要修改的特性在可對應功能的.h文件修改
#主要功能
>1.與手機音頻通信  
2.按下按鍵后發送當前值(高位從FF每次自減1,低位從00每次自加1)  
3.接收手機發送的值  
4.插入手機后MCU自動喚醒,拔出耳機口自動休眠  

#程序流程
>##上電
1.完成各項初始值配置后進入休眠
>##自動喚醒
1.插入手機后自動喚醒  
2.自動開始接收手機發送過來的信息  
3.按下按鍵后發送值每次高位自減1,低位自加1發送到手機上  
4.拔出手機后自動休眠


#顯示說明
>1.上電休眠無顯示  
2.按下發送后顯示發送的值,前兩位為第一筆Data,后兩位為第二筆Data  
3.若接收到數據顯示接收值,前兩位為第一筆Data,后兩位為第二筆Data  
3.若出現錯誤顯示EEEE表示ERROR  
#手機端APP說明
>1 目前測試HTC ONE M7 收發正常,其他機型還需測試  
2.開啟APP后按下Receive后即可接收MCU端的數據  
3.在兩個輸入對話框內分別輸入第一筆和第一筆Byte數據(超過255自動取余)，按下發送即可將數據發送到MCU端