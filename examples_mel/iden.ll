; ModuleID = 'iden.c'
source_filename = "iden.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [15 x i8] c"Array Size: %d\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local void @identity([5 x i32]* noundef %a) #0 !dbg !8 {
entry:
  %a.addr = alloca [5 x i32]*, align 8
  %loop_i = alloca i32, align 4
  %loop_j = alloca i32, align 4
  %loop_k = alloca i32, align 4
  store [5 x i32]* %a, [5 x i32]** %a.addr, align 8
  call void @llvm.dbg.declare(metadata [5 x i32]** %a.addr, metadata !17, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.declare(metadata i32* %loop_i, metadata !19, metadata !DIExpression()), !dbg !20
  call void @llvm.dbg.declare(metadata i32* %loop_j, metadata !21, metadata !DIExpression()), !dbg !22
  call void @llvm.dbg.declare(metadata i32* %loop_k, metadata !23, metadata !DIExpression()), !dbg !24
  store i32 0, i32* %loop_i, align 4, !dbg !25
  br label %for.cond, !dbg !27

for.cond:                                         ; preds = %for.inc6, %entry
  %0 = load i32, i32* %loop_i, align 4, !dbg !28
  %cmp = icmp slt i32 %0, 5, !dbg !30
  br i1 %cmp, label %for.body, label %for.end8, !dbg !31

for.body:                                         ; preds = %for.cond
  store i32 0, i32* %loop_j, align 4, !dbg !32
  br label %for.cond1, !dbg !35

for.cond1:                                        ; preds = %for.inc, %for.body
  %1 = load i32, i32* %loop_j, align 4, !dbg !36
  %cmp2 = icmp slt i32 %1, 5, !dbg !38
  br i1 %cmp2, label %for.body3, label %for.end, !dbg !39

for.body3:                                        ; preds = %for.cond1
  %2 = load [5 x i32]*, [5 x i32]** %a.addr, align 8, !dbg !40
  %3 = load i32, i32* %loop_i, align 4, !dbg !42
  %idxprom = sext i32 %3 to i64, !dbg !40
  %arrayidx = getelementptr inbounds [5 x i32], [5 x i32]* %2, i64 %idxprom, !dbg !40
  %4 = load i32, i32* %loop_j, align 4, !dbg !43
  %idxprom4 = sext i32 %4 to i64, !dbg !40
  %arrayidx5 = getelementptr inbounds [5 x i32], [5 x i32]* %arrayidx, i64 0, i64 %idxprom4, !dbg !40
  store i32 0, i32* %arrayidx5, align 4, !dbg !44
  br label %for.inc, !dbg !45

for.inc:                                          ; preds = %for.body3
  %5 = load i32, i32* %loop_j, align 4, !dbg !46
  %inc = add nsw i32 %5, 1, !dbg !46
  store i32 %inc, i32* %loop_j, align 4, !dbg !46
  br label %for.cond1, !dbg !47, !llvm.loop !48

for.end:                                          ; preds = %for.cond1
  br label %for.inc6, !dbg !51

for.inc6:                                         ; preds = %for.end
  %6 = load i32, i32* %loop_i, align 4, !dbg !52
  %inc7 = add nsw i32 %6, 1, !dbg !52
  store i32 %inc7, i32* %loop_i, align 4, !dbg !52
  br label %for.cond, !dbg !53, !llvm.loop !54

for.end8:                                         ; preds = %for.cond
  store i32 0, i32* %loop_k, align 4, !dbg !56
  br label %for.cond9, !dbg !58

for.cond9:                                        ; preds = %for.inc16, %for.end8
  %7 = load i32, i32* %loop_k, align 4, !dbg !59
  %cmp10 = icmp slt i32 %7, 5, !dbg !61
  br i1 %cmp10, label %for.body11, label %for.end18, !dbg !62

for.body11:                                       ; preds = %for.cond9
  %8 = load [5 x i32]*, [5 x i32]** %a.addr, align 8, !dbg !63
  %9 = load i32, i32* %loop_k, align 4, !dbg !65
  %idxprom12 = sext i32 %9 to i64, !dbg !63
  %arrayidx13 = getelementptr inbounds [5 x i32], [5 x i32]* %8, i64 %idxprom12, !dbg !63
  %10 = load i32, i32* %loop_k, align 4, !dbg !66
  %idxprom14 = sext i32 %10 to i64, !dbg !63
  %arrayidx15 = getelementptr inbounds [5 x i32], [5 x i32]* %arrayidx13, i64 0, i64 %idxprom14, !dbg !63
  store i32 1, i32* %arrayidx15, align 4, !dbg !67
  br label %for.inc16, !dbg !68

for.inc16:                                        ; preds = %for.body11
  %11 = load i32, i32* %loop_k, align 4, !dbg !69
  %inc17 = add nsw i32 %11, 1, !dbg !69
  store i32 %inc17, i32* %loop_k, align 4, !dbg !69
  br label %for.cond9, !dbg !70, !llvm.loop !71

for.end18:                                        ; preds = %for.cond9
  ret void, !dbg !73
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !74 {
entry:
  %retval = alloca i32, align 4
  %a = alloca [5 x [5 x i32]], align 16
  %a_size = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata [5 x [5 x i32]]* %a, metadata !77, metadata !DIExpression()), !dbg !80
  %arraydecay = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %a, i64 0, i64 0, !dbg !81
  call void @identity([5 x i32]* noundef %arraydecay), !dbg !82
  call void @llvm.dbg.declare(metadata i32* %a_size, metadata !83, metadata !DIExpression()), !dbg !84
  store i32 25, i32* %a_size, align 4, !dbg !84
  %0 = load i32, i32* %a_size, align 4, !dbg !85
  %call = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([15 x i8], [15 x i8]* @.str, i64 0, i64 0), i32 noundef %0), !dbg !86
  ret i32 0, !dbg !87
}

declare dso_local i32 @printf(i8* noundef, ...) #2

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "iden.c", directory: "/home/users/shravank/projects/meliora2/Meliora/examples_mel", checksumkind: CSK_MD5, checksum: "e62aca0071816fd5816ae816b5cceff4")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"uwtable", i32 1}
!6 = !{i32 7, !"frame-pointer", i32 2}
!7 = !{!"clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)"}
!8 = distinct !DISubprogram(name: "identity", scope: !1, file: !1, line: 7, type: !9, scopeLine: 7, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!9 = !DISubroutineType(types: !10)
!10 = !{null, !11}
!11 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !12, size: 64)
!12 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 160, elements: !14)
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !{!15}
!15 = !DISubrange(count: 5)
!16 = !{}
!17 = !DILocalVariable(name: "a", arg: 1, scope: !8, file: !1, line: 7, type: !11)
!18 = !DILocation(line: 7, column: 19, scope: !8)
!19 = !DILocalVariable(name: "loop_i", scope: !8, file: !1, line: 9, type: !13)
!20 = !DILocation(line: 9, column: 9, scope: !8)
!21 = !DILocalVariable(name: "loop_j", scope: !8, file: !1, line: 9, type: !13)
!22 = !DILocation(line: 9, column: 16, scope: !8)
!23 = !DILocalVariable(name: "loop_k", scope: !8, file: !1, line: 9, type: !13)
!24 = !DILocation(line: 9, column: 23, scope: !8)
!25 = !DILocation(line: 11, column: 15, scope: !26)
!26 = distinct !DILexicalBlock(scope: !8, file: !1, line: 11, column: 5)
!27 = !DILocation(line: 11, column: 9, scope: !26)
!28 = !DILocation(line: 11, column: 19, scope: !29)
!29 = distinct !DILexicalBlock(scope: !26, file: !1, line: 11, column: 5)
!30 = !DILocation(line: 11, column: 25, scope: !29)
!31 = !DILocation(line: 11, column: 5, scope: !26)
!32 = !DILocation(line: 12, column: 19, scope: !33)
!33 = distinct !DILexicalBlock(scope: !34, file: !1, line: 12, column: 9)
!34 = distinct !DILexicalBlock(scope: !29, file: !1, line: 11, column: 38)
!35 = !DILocation(line: 12, column: 13, scope: !33)
!36 = !DILocation(line: 12, column: 23, scope: !37)
!37 = distinct !DILexicalBlock(scope: !33, file: !1, line: 12, column: 9)
!38 = !DILocation(line: 12, column: 29, scope: !37)
!39 = !DILocation(line: 12, column: 9, scope: !33)
!40 = !DILocation(line: 13, column: 13, scope: !41)
!41 = distinct !DILexicalBlock(scope: !37, file: !1, line: 12, column: 42)
!42 = !DILocation(line: 13, column: 15, scope: !41)
!43 = !DILocation(line: 13, column: 23, scope: !41)
!44 = !DILocation(line: 13, column: 30, scope: !41)
!45 = !DILocation(line: 14, column: 9, scope: !41)
!46 = !DILocation(line: 12, column: 39, scope: !37)
!47 = !DILocation(line: 12, column: 9, scope: !37)
!48 = distinct !{!48, !39, !49, !50}
!49 = !DILocation(line: 14, column: 9, scope: !33)
!50 = !{!"llvm.loop.mustprogress"}
!51 = !DILocation(line: 15, column: 5, scope: !34)
!52 = !DILocation(line: 11, column: 35, scope: !29)
!53 = !DILocation(line: 11, column: 5, scope: !29)
!54 = distinct !{!54, !31, !55, !50}
!55 = !DILocation(line: 15, column: 5, scope: !26)
!56 = !DILocation(line: 17, column: 15, scope: !57)
!57 = distinct !DILexicalBlock(scope: !8, file: !1, line: 17, column: 5)
!58 = !DILocation(line: 17, column: 9, scope: !57)
!59 = !DILocation(line: 17, column: 19, scope: !60)
!60 = distinct !DILexicalBlock(scope: !57, file: !1, line: 17, column: 5)
!61 = !DILocation(line: 17, column: 25, scope: !60)
!62 = !DILocation(line: 17, column: 5, scope: !57)
!63 = !DILocation(line: 18, column: 9, scope: !64)
!64 = distinct !DILexicalBlock(scope: !60, file: !1, line: 17, column: 38)
!65 = !DILocation(line: 18, column: 11, scope: !64)
!66 = !DILocation(line: 18, column: 19, scope: !64)
!67 = !DILocation(line: 18, column: 26, scope: !64)
!68 = !DILocation(line: 19, column: 5, scope: !64)
!69 = !DILocation(line: 17, column: 35, scope: !60)
!70 = !DILocation(line: 17, column: 5, scope: !60)
!71 = distinct !{!71, !62, !72, !50}
!72 = !DILocation(line: 19, column: 5, scope: !57)
!73 = !DILocation(line: 20, column: 1, scope: !8)
!74 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 22, type: !75, scopeLine: 22, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!75 = !DISubroutineType(types: !76)
!76 = !{!13}
!77 = !DILocalVariable(name: "a", scope: !74, file: !1, line: 25, type: !78)
!78 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 800, elements: !79)
!79 = !{!15, !15}
!80 = !DILocation(line: 25, column: 9, scope: !74)
!81 = !DILocation(line: 27, column: 14, scope: !74)
!82 = !DILocation(line: 27, column: 5, scope: !74)
!83 = !DILocalVariable(name: "a_size", scope: !74, file: !1, line: 29, type: !13)
!84 = !DILocation(line: 29, column: 9, scope: !74)
!85 = !DILocation(line: 30, column: 29, scope: !74)
!86 = !DILocation(line: 30, column: 5, scope: !74)
!87 = !DILocation(line: 32, column: 5, scope: !74)
