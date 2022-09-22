idf_component_register(SRCS "commands.c"
                            "esp_console_repl.c"
                            "split_argv.c"
                            "argtable3/argtable3.c"
                            "linenoise/linenoise.c"
                            "main.c"
                            
                           
                    INCLUDE_DIRS "."
                    REQUIRES vfs  nvs_flash )
