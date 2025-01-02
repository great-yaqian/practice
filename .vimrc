" An example for a vimrc file.
"
" Maintainer:   Bram Moolenaar <Bram@vim.org>
" Last change:  2008 Jul 02
"
" To use it, copy it to
"     for Unix and OS/2:  ~/.vimrc
"         for Amiga:  s:.vimrc
"  for MS-DOS and Win32:  $VIM\_vimrc
"       for OpenVMS:  sys$login:.vimrc

" When started as "evim", evim.vim will already have done these settings.
if v:progname =~? "evim"
  finish
endif

" Use Vim settings, rather then Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
set nocompatible

" allow backspacing over everything in insert mode
set backspace=indent,eol,start

if has("vms")
  set nobackup      " do not keep a backup file, use versions instead
else
  set nobackup      " keep a backup file
endif
set history=50      " keep 50 lines of command line history
set ruler       " show the cursor position all the time
set showcmd     " display incomplete commands
set incsearch       " do incremental searching

" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
map Q gq

" CTRL-U in insert mode deletes a lot.  Use CTRL-G u to first break undo,
" so that you can undo CTRL-U after inserting a line break.
inoremap <C-U> <C-G>u<C-U>

" In many terminal emulators the mouse works just fine, thus enable it.
if has('mouse')
  set mouse=a
endif

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

" Convenient command to see the difference between the current buffer and the
" file it was loaded from, thus the changes you made.
" Only define it when not defined already.
if !exists(":DiffOrig")
  command DiffOrig vert new | set bt=nofile | r # | 0d_ | diffthis
          \ | wincmd p | diffthis
endif

colorscheme desert

set linespace=5
set number
set shiftwidth=4
set softtabstop=4
set tabstop=4
set autoindent

set showmatch

set cursorcolumn
set cursorline
set listchars=tab:>-,trail:-
set guifont=Monospace\ 14
set lines=40
set columns=130
set linebreak

"set window auto centercenter
function WindowCenterInScreen()
    set lines=9999 columns=9999
    let g:windowsSizeFixX = 78
    let g:windowsSizeFixY = 118
    let g:windowsScaleX = 7.75
    let g:windowsScaleY = 17.0
    let g:windowsPosOldX = getwinposx()
    let g:windowsPosOldY = getwinposy()
    let g:windowsScreenWidth = float2nr(winwidth(0) * g:windowsScaleX) + g:windowsPosOldX + g:windowsSizeFixX
    let g:windowsScreenHeight = float2nr(winheight(0) * g:windowsScaleY) + g:windowsPosOldY + g:windowsSizeFixY
    set lines=35 columns=150
    let g:windowsSizeWidth = float2nr(winwidth(0) * g:windowsScaleX) + g:windowsSizeFixX
    let g:windowsSizeHeight = float2nr(winheight(0) * g:windowsScaleY) + g:windowsSizeFixY
    let g:windowsPosX = ((g:windowsScreenWidth - g:windowsSizeWidth) / 2)
    let g:windowsPosY = ((g:windowsScreenHeight - g:windowsSizeHeight) / 2)
    exec ':winpos ' . g:windowsPosX . ' ' . g:windowsPosY
endfunc
au GUIEnter * call WindowCenterInScreen()
hi Search   guibg=peru guifg=grey30
"hi Search  guibg=peru guifg=wheat
map E ge
map dw daw
"map cw caw

"let b:match_word='\<ifdef\>:\<endif\>'
"let b:matchit_ignorecase=1
set ignorecase
set expandtab
set encoding=utf-8
%ret! 4
"let b:match_word='\<begin\>:\<end\>,'
"    \ . '\<while\>:\<continue\>:<break\>:\<endwhile\>,'
"    \ . '\<if\>:\<else if\>:<else\>,'
"    \ . '\<module\>:\<endmodule\>,'
"    \ . '\<task\>:\<endtask\>,'
"    \ . '\<function\>:\<endfunction\>,'
"    \ . '\<program\>:\<endprogram\>'
"let b:matchit_ignorecase=1    

au BufNewFile,BufRead *.drc,*.lvs,*.xrc,*.xact,*.svrf,*rules,*.extract,*.rule,*.tvf,*.layer,*.log set syntax=calibre
