# ffmpegtest

#SDL
testffmpeg.c 
```
/* Open the media file */
    result = avformat_open_input(&ic, file, NULL, NULL);
    if (result < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't open %s: %d", argv[1], result);                                                                                            return_code = 4;
        goto quit;
}

+++++++
    if ((result=avformat_find_stream_info(ic, NULL)) < 0) {
           printf("cannot retrive video info\n");
}
```
