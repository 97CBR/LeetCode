    // //监视C盘根目录下文件名改变的例子，其中while循环一直监控，直到程序关闭
    // HANDLE hChangeHandle = FindFirstChangeNotification("D:\\", true, FILE_NOTIFY_CHANGE_FILE_NAME);
    // //判断是否设置成功
    // if (hChangeHandle == INVALID_HANDLE_VALUE)
    // {
    //     printf("Find First Change Notification failed\n");
    //     ExitProcess(GetLastError());
    //     return 0;
    // }
    // //等待通知
    // printf("These change a file name\n");
    // //循环等待
    // while (true)
    //     if (FindNextChangeNotification(hChangeHandle))
    //     {
    //         printf("These change a file name\n");
    //         //结束监视程序调用FindCloseChangeNotification关闭句柄
    //     }
    // FindCloseChangeNotification(hChangeHandle);
    // getch(); //按键退出程序