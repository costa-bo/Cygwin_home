"dein Scripts-----------------------------
if &compatible
  set nocompatible               " Be iMproved
endif

" Required:
set runtimepath+=/root/.vim/bundles/repos/github.com/Shougo/dein.vim

" Required:
if dein#load_state('/root/.vim/bundles')
  call dein#begin('/root/.vim/bundles')

  " Let dein manage dein
  " Required:
  call dein#add('/root/.vim/bundles/repos/github.com/Shougo/dein.vim')

  " Add or remove your plugins here:
  call dein#add('Shougo/neosnippet.vim')
  call dein#add('Shougo/neosnippet-snippets')

  " You can specify revision/branch/tag.
  call dein#add('Shougo/vimshell', { 'rev': '3787e5' })

  " Required:
  call dein#end()
  call dein#save_state()
endif

" Required:
filetype plugin indent on
syntax enable

" If you want to install not installed plugins on startup.
"if dein#check_install()
"  call dein#install()
"endif

"End dein Scripts-------------------------


set shiftwidth=4  " use 4 spaces for the autoindenting feature
set runtimepath+=~/.vim,~/.vim/after
set packpath+=~/.vim
source ~/.vimrc

    if has('nvim')
        tnoremap <Esc> <C-\><C-n>
    endif
