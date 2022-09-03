" Cmbal syntax file for Vim/Neovim
" Language: Cmbal

" save current cpo configuration
:if exists("b:current_syntax")
:  finish
:endif

:let s:cpo_save = &cpo
:set cpo&vim

" keywords
:syntax keyword cmbalKeyword varfn function

" builtin functions
:syntax keyword cmbaFunctions writeln

:highlight link cmbalKeyword Keyword
:highlight link cmbaFunctions Function

:let b:current_syntax = "cmbal"

" reset the previous cpo configuration
:let &cpo = s:cpo_save
:unlet! s:cpo_save
