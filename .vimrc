set nocompatible
set encoding=utf8
set fileencoding=utf8
set termencoding=utf8
set t_Co=256

filetype off                  " required

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/nerdtree'
Plugin 'valloric/youcompleteme'
Plugin 'majutsushi/tagbar'
Plugin 'flazz/vim-colorschemes'
Plugin 'yggdroot/indentline'
Plugin 'bling/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'tpope/vim-fugitive'

call vundle#end()            " required
filetype plugin indent on    " required

syntax on
set number
set cursorline
set shiftwidth=4
set tabstop=4
autocmd FileType cpp :set expandtab
colorscheme wombat256 
set laststatus=2

"----------------------IndentLine
let g:indentLine_leadingSpaceEnabled = 1
let g:indentLine_leadingSpaceChar = '·'
let g:indentLine_char = '>'
"----------------------NERDTree
map <F7> :NERDTreeToggle<CR>

"----------------------Tagbar
nmap <F8> :TagbarToggle<CR>

"----------------------YCM
let g:ycm_global_ycm_extra_conf = '~/.vim/.ycm_extra_conf.py'
let g:ycm_confirm_extra_conf = 0
let g:ycm_key_list_select_completion = ['', '']
let g:ycm_key_list_previous_completion = ['', '']
let g:ycm_autoclose_preview_window_after_completion = 1
let g:ycm_warning_symbol = '>*'
let g:ycm_min_num_of_chars_for_completion = 1    " 기본값은 2입니다. 문자가 1개 입력되면 그 때부터 자동완성을 시작합니다. 쓰지 않을려면 99같은 큰 값을 넣어줍니다.

let g:ycm_auto_trigger = 1    " 기본값은 1입니다. '.'이나 '->'을 받으면 자동으로 목록들을 출력해주죠.
let g:ycm_collect_identifiers_from_tags_files = 1    " tags 파일을 사용합니다. 성능상 이익이 있는걸로 알고 있습니다.

"-----------------------Vim airline
let g:airline#extensions#tabline#enabled = 1
let g:airline_theme='wombat'
let g:airline#extensions#tabline#left_sep = ' '
let g:airline#extensions#tabline#left_alt_sep = '|'
let g:airline_powerline_fonts = 1
let g:airline#extensions#ycm#enabled = 1
let g:airline#extensions#ycm#error_symbol = 'E:' 
let g:airline#extensions#ycm#warning_symbol = 'W:'
"-----------------------compile
nmap <F5> :!sudo clang++ -std=c++11 -stdlib=libc++ -lc++abi % -o %.exe <CR>

