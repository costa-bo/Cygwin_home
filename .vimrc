"----------- Vundle Plugin -----------------
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
"Plugin 'tpope/vim-fugitive'
Plugin 'scrooloose/nerdtree'
Plugin 'vim-scripts/IndexedSearch'
Plugin 'vim-scripts/Mark--Karkat'
Plugin 'vim-scripts/CCTree'
Plugin 'vim-scripts/Conque-GDB'
"Plugin 'Valloric/YouCompleteMe'
"Plugin 'klen/python-mode'
Plugin 'vim-scripts/Tabmerge'
Plugin 'uguu-org/vim-matrix-screensaver'
Plugin 'vim-scripts/TeTrIs.vim'
Plugin 'sjl/badwolf'
Plugin 'majutsushi/tagbar'

" plugin from http://vim-scripts.org/vim/scripts.html
"Plugin 'L9'

" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'

" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'

" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
"Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}

" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
"Plugin 'ascenator/L9', {'name': 'newL9'}

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

let g:ctrlp_working_path_mode = 0
let g:ctrlp_max_files = 0
let g:ctrlp_user_command = ['.svn/','cat %s/cscope.files']

set tags=$NG_ROOT/tags,tags; " tell Vim where to find your tags
set tags=tags;/

set cursorline    " cursor line
set laststatus=2  " display the status line always
set statusline+=%f\:%l(%L)\ %P\ %m\ %r
set number        " always show line numbers
set expandtab     " instead of tabs enter <tabstop> spaces when pressing <TAB> key
set shiftwidth=4  " use 4 spaces for the autoindenting feature
set tabstop=4     " a tab is 4 spaces
set ignorecase    " ignore case when searching
set incsearch     " incremental search (start search while typing)
set hlsearch      " highlights search text
set showcmd       " count lines in Visual Mode
set mouse=a       " enable using the mouse if terminal emulator
"set t_ti=""       " NO!!! very dangerus comand

" it skata kanoun auta?
set showmode      " always show what mode we're currently editing in
set clipboard=unnamed           " normal OS clipboard interaction
set ttymouse=xterm2
syntax enable

let mapleader=","

colorscheme badwolf

nmap <C-@>s <C-W><C-S> :cs find s <C-R>=expand("<cword>")<CR><CR>

map <C-h> <C-W>h
map <C-l> <C-W>l
map <C-j> <C-W>j
map <C-k> <C-W>k

"open a NERDTree automatically when vim starts up if no files were specified
"autocmd StdinReadPre * let s:std_in=1
"autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif

" \-a grep the word to current dir
nnoremap <leader>a :silent execute "grep! -R --include=\*.{c,cpp,h,py} --exclude-dir=./SS_6WIND* " . shellescape('<cword>') .  " ."<cr>:copen 12<cr>:redraw!<cr>
nnoremap <leader>A :silent execute "grep! -R --include=\*.{c,cpp,h,py} --exclude-dir=./SS_6WIND* " . shellescape('<cWORD>') .  " ."<cr>:copen 12<cr>:redraw!<cr>

