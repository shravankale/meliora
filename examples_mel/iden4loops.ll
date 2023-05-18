; ModuleID = 'iden4loops.c'
source_filename = "iden4loops.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [15 x i8] c"Array Size: %d\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@.str.2 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local void @identity([5 x i32]* noundef %a) #0 !dbg !8 {
entry:
  %a.addr = alloca [5 x i32]*, align 8
  %loop_i = alloca i32, align 4
  %loop_j = alloca i32, align 4
  %loop_k = alloca i32, align 4
  %loop_l = alloca i32, align 4
  store [5 x i32]* %a, [5 x i32]** %a.addr, align 8
  call void @llvm.dbg.declare(metadata [5 x i32]** %a.addr, metadata !17, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.declare(metadata i32* %loop_i, metadata !19, metadata !DIExpression()), !dbg !20
  call void @llvm.dbg.declare(metadata i32* %loop_j, metadata !21, metadata !DIExpression()), !dbg !22
  call void @llvm.dbg.declare(metadata i32* %loop_k, metadata !23, metadata !DIExpression()), !dbg !24
  call void @llvm.dbg.declare(metadata i32* %loop_l, metadata !25, metadata !DIExpression()), !dbg !26
  store i32 0, i32* %loop_i, align 4, !dbg !27
  br label %for.cond, !dbg !29

for.cond:                                         ; preds = %for.inc6, %entry
  %0 = load i32, i32* %loop_i, align 4, !dbg !30
  %cmp = icmp slt i32 %0, 5, !dbg !32
  br i1 %cmp, label %for.body, label %for.end8, !dbg !33

for.body:                                         ; preds = %for.cond
  store i32 0, i32* %loop_j, align 4, !dbg !34
  br label %for.cond1, !dbg !37

for.cond1:                                        ; preds = %for.inc, %for.body
  %1 = load i32, i32* %loop_j, align 4, !dbg !38
  %cmp2 = icmp slt i32 %1, 5, !dbg !40
  br i1 %cmp2, label %for.body3, label %for.end, !dbg !41

for.body3:                                        ; preds = %for.cond1
  %2 = load [5 x i32]*, [5 x i32]** %a.addr, align 8, !dbg !42
  %3 = load i32, i32* %loop_i, align 4, !dbg !44
  %idxprom = sext i32 %3 to i64, !dbg !42
  %arrayidx = getelementptr inbounds [5 x i32], [5 x i32]* %2, i64 %idxprom, !dbg !42
  %4 = load i32, i32* %loop_j, align 4, !dbg !45
  %idxprom4 = sext i32 %4 to i64, !dbg !42
  %arrayidx5 = getelementptr inbounds [5 x i32], [5 x i32]* %arrayidx, i64 0, i64 %idxprom4, !dbg !42
  store i32 0, i32* %arrayidx5, align 4, !dbg !46
  br label %for.inc, !dbg !47

for.inc:                                          ; preds = %for.body3
  %5 = load i32, i32* %loop_j, align 4, !dbg !48
  %inc = add nsw i32 %5, 1, !dbg !48
  store i32 %inc, i32* %loop_j, align 4, !dbg !48
  br label %for.cond1, !dbg !49, !llvm.loop !50

for.end:                                          ; preds = %for.cond1
  br label %for.inc6, !dbg !53

for.inc6:                                         ; preds = %for.end
  %6 = load i32, i32* %loop_i, align 4, !dbg !54
  %inc7 = add nsw i32 %6, 1, !dbg !54
  store i32 %inc7, i32* %loop_i, align 4, !dbg !54
  br label %for.cond, !dbg !55, !llvm.loop !56

for.end8:                                         ; preds = %for.cond
  store i32 0, i32* %loop_k, align 4, !dbg !58
  br label %for.cond9, !dbg !60

for.cond9:                                        ; preds = %for.inc23, %for.end8
  %7 = load i32, i32* %loop_k, align 4, !dbg !61
  %cmp10 = icmp slt i32 %7, 5, !dbg !63
  br i1 %cmp10, label %for.body11, label %for.end25, !dbg !64

for.body11:                                       ; preds = %for.cond9
  store i32 0, i32* %loop_l, align 4, !dbg !65
  br label %for.cond12, !dbg !68

for.cond12:                                       ; preds = %for.inc20, %for.body11
  %8 = load i32, i32* %loop_l, align 4, !dbg !69
  %cmp13 = icmp slt i32 %8, 5, !dbg !71
  br i1 %cmp13, label %for.body14, label %for.end22, !dbg !72

for.body14:                                       ; preds = %for.cond12
  %9 = load i32, i32* %loop_k, align 4, !dbg !73
  %10 = load i32, i32* %loop_l, align 4, !dbg !76
  %cmp15 = icmp eq i32 %9, %10, !dbg !77
  br i1 %cmp15, label %if.then, label %if.end, !dbg !78

if.then:                                          ; preds = %for.body14
  %11 = load [5 x i32]*, [5 x i32]** %a.addr, align 8, !dbg !79
  %12 = load i32, i32* %loop_l, align 4, !dbg !81
  %idxprom16 = sext i32 %12 to i64, !dbg !79
  %arrayidx17 = getelementptr inbounds [5 x i32], [5 x i32]* %11, i64 %idxprom16, !dbg !79
  %13 = load i32, i32* %loop_l, align 4, !dbg !82
  %idxprom18 = sext i32 %13 to i64, !dbg !79
  %arrayidx19 = getelementptr inbounds [5 x i32], [5 x i32]* %arrayidx17, i64 0, i64 %idxprom18, !dbg !79
  store i32 1, i32* %arrayidx19, align 4, !dbg !83
  br label %if.end, !dbg !84

if.end:                                           ; preds = %if.then, %for.body14
  br label %for.inc20, !dbg !85

for.inc20:                                        ; preds = %if.end
  %14 = load i32, i32* %loop_l, align 4, !dbg !86
  %inc21 = add nsw i32 %14, 1, !dbg !86
  store i32 %inc21, i32* %loop_l, align 4, !dbg !86
  br label %for.cond12, !dbg !87, !llvm.loop !88

for.end22:                                        ; preds = %for.cond12
  br label %for.inc23, !dbg !90

for.inc23:                                        ; preds = %for.end22
  %15 = load i32, i32* %loop_k, align 4, !dbg !91
  %inc24 = add nsw i32 %15, 1, !dbg !91
  store i32 %inc24, i32* %loop_k, align 4, !dbg !91
  br label %for.cond9, !dbg !92, !llvm.loop !93

for.end25:                                        ; preds = %for.cond9
  ret void, !dbg !95
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !96 {
entry:
  %retval = alloca i32, align 4
  %a = alloca [5 x [5 x i32]], align 16
  %a_size = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata [5 x [5 x i32]]* %a, metadata !99, metadata !DIExpression()), !dbg !102
  %arraydecay = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %a, i64 0, i64 0, !dbg !103
  call void @identity([5 x i32]* noundef %arraydecay), !dbg !104
  call void @llvm.dbg.declare(metadata i32* %a_size, metadata !105, metadata !DIExpression()), !dbg !106
  store i32 25, i32* %a_size, align 4, !dbg !106
  %0 = load i32, i32* %a_size, align 4, !dbg !107
  %call = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([15 x i8], [15 x i8]* @.str, i64 0, i64 0), i32 noundef %0), !dbg !108
  call void @llvm.dbg.declare(metadata i32* %i, metadata !109, metadata !DIExpression()), !dbg !111
  store i32 0, i32* %i, align 4, !dbg !111
  br label %for.cond, !dbg !112

for.cond:                                         ; preds = %for.inc8, %entry
  %1 = load i32, i32* %i, align 4, !dbg !113
  %cmp = icmp slt i32 %1, 5, !dbg !115
  br i1 %cmp, label %for.body, label %for.end10, !dbg !116

for.body:                                         ; preds = %for.cond
  call void @llvm.dbg.declare(metadata i32* %j, metadata !117, metadata !DIExpression()), !dbg !120
  store i32 0, i32* %j, align 4, !dbg !120
  br label %for.cond1, !dbg !121

for.cond1:                                        ; preds = %for.inc, %for.body
  %2 = load i32, i32* %j, align 4, !dbg !122
  %cmp2 = icmp slt i32 %2, 5, !dbg !124
  br i1 %cmp2, label %for.body3, label %for.end, !dbg !125

for.body3:                                        ; preds = %for.cond1
  %3 = load i32, i32* %i, align 4, !dbg !126
  %idxprom = sext i32 %3 to i64, !dbg !128
  %arrayidx = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %a, i64 0, i64 %idxprom, !dbg !128
  %4 = load i32, i32* %j, align 4, !dbg !129
  %idxprom4 = sext i32 %4 to i64, !dbg !128
  %arrayidx5 = getelementptr inbounds [5 x i32], [5 x i32]* %arrayidx, i64 0, i64 %idxprom4, !dbg !128
  %5 = load i32, i32* %arrayidx5, align 4, !dbg !128
  %call6 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 noundef %5), !dbg !130
  br label %for.inc, !dbg !131

for.inc:                                          ; preds = %for.body3
  %6 = load i32, i32* %j, align 4, !dbg !132
  %inc = add nsw i32 %6, 1, !dbg !132
  store i32 %inc, i32* %j, align 4, !dbg !132
  br label %for.cond1, !dbg !133, !llvm.loop !134

for.end:                                          ; preds = %for.cond1
  %call7 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.2, i64 0, i64 0)), !dbg !136
  br label %for.inc8, !dbg !137

for.inc8:                                         ; preds = %for.end
  %7 = load i32, i32* %i, align 4, !dbg !138
  %inc9 = add nsw i32 %7, 1, !dbg !138
  store i32 %inc9, i32* %i, align 4, !dbg !138
  br label %for.cond, !dbg !139, !llvm.loop !140

for.end10:                                        ; preds = %for.cond
  ret i32 0, !dbg !142
}

declare dso_local i32 @printf(i8* noundef, ...) #2

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "iden4loops.c", directory: "/home/users/shravank/projects/meliora2/Meliora/examples_mel", checksumkind: CSK_MD5, checksum: "aef025a3bc9fe508cb64432ad9eaeaca")
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
!25 = !DILocalVariable(name: "loop_l", scope: !8, file: !1, line: 9, type: !13)
!26 = !DILocation(line: 9, column: 31, scope: !8)
!27 = !DILocation(line: 11, column: 15, scope: !28)
!28 = distinct !DILexicalBlock(scope: !8, file: !1, line: 11, column: 5)
!29 = !DILocation(line: 11, column: 9, scope: !28)
!30 = !DILocation(line: 11, column: 19, scope: !31)
!31 = distinct !DILexicalBlock(scope: !28, file: !1, line: 11, column: 5)
!32 = !DILocation(line: 11, column: 25, scope: !31)
!33 = !DILocation(line: 11, column: 5, scope: !28)
!34 = !DILocation(line: 12, column: 19, scope: !35)
!35 = distinct !DILexicalBlock(scope: !36, file: !1, line: 12, column: 9)
!36 = distinct !DILexicalBlock(scope: !31, file: !1, line: 11, column: 38)
!37 = !DILocation(line: 12, column: 13, scope: !35)
!38 = !DILocation(line: 12, column: 23, scope: !39)
!39 = distinct !DILexicalBlock(scope: !35, file: !1, line: 12, column: 9)
!40 = !DILocation(line: 12, column: 29, scope: !39)
!41 = !DILocation(line: 12, column: 9, scope: !35)
!42 = !DILocation(line: 13, column: 13, scope: !43)
!43 = distinct !DILexicalBlock(scope: !39, file: !1, line: 12, column: 42)
!44 = !DILocation(line: 13, column: 15, scope: !43)
!45 = !DILocation(line: 13, column: 23, scope: !43)
!46 = !DILocation(line: 13, column: 30, scope: !43)
!47 = !DILocation(line: 14, column: 9, scope: !43)
!48 = !DILocation(line: 12, column: 39, scope: !39)
!49 = !DILocation(line: 12, column: 9, scope: !39)
!50 = distinct !{!50, !41, !51, !52}
!51 = !DILocation(line: 14, column: 9, scope: !35)
!52 = !{!"llvm.loop.mustprogress"}
!53 = !DILocation(line: 15, column: 5, scope: !36)
!54 = !DILocation(line: 11, column: 35, scope: !31)
!55 = !DILocation(line: 11, column: 5, scope: !31)
!56 = distinct !{!56, !33, !57, !52}
!57 = !DILocation(line: 15, column: 5, scope: !28)
!58 = !DILocation(line: 17, column: 15, scope: !59)
!59 = distinct !DILexicalBlock(scope: !8, file: !1, line: 17, column: 5)
!60 = !DILocation(line: 17, column: 9, scope: !59)
!61 = !DILocation(line: 17, column: 19, scope: !62)
!62 = distinct !DILexicalBlock(scope: !59, file: !1, line: 17, column: 5)
!63 = !DILocation(line: 17, column: 25, scope: !62)
!64 = !DILocation(line: 17, column: 5, scope: !59)
!65 = !DILocation(line: 18, column: 19, scope: !66)
!66 = distinct !DILexicalBlock(scope: !67, file: !1, line: 18, column: 9)
!67 = distinct !DILexicalBlock(scope: !62, file: !1, line: 17, column: 38)
!68 = !DILocation(line: 18, column: 13, scope: !66)
!69 = !DILocation(line: 18, column: 23, scope: !70)
!70 = distinct !DILexicalBlock(scope: !66, file: !1, line: 18, column: 9)
!71 = !DILocation(line: 18, column: 29, scope: !70)
!72 = !DILocation(line: 18, column: 9, scope: !66)
!73 = !DILocation(line: 19, column: 16, scope: !74)
!74 = distinct !DILexicalBlock(scope: !75, file: !1, line: 19, column: 16)
!75 = distinct !DILexicalBlock(scope: !70, file: !1, line: 18, column: 42)
!76 = !DILocation(line: 19, column: 24, scope: !74)
!77 = !DILocation(line: 19, column: 22, scope: !74)
!78 = !DILocation(line: 19, column: 16, scope: !75)
!79 = !DILocation(line: 20, column: 17, scope: !80)
!80 = distinct !DILexicalBlock(scope: !74, file: !1, line: 19, column: 31)
!81 = !DILocation(line: 20, column: 19, scope: !80)
!82 = !DILocation(line: 20, column: 27, scope: !80)
!83 = !DILocation(line: 20, column: 34, scope: !80)
!84 = !DILocation(line: 21, column: 13, scope: !80)
!85 = !DILocation(line: 22, column: 9, scope: !75)
!86 = !DILocation(line: 18, column: 39, scope: !70)
!87 = !DILocation(line: 18, column: 9, scope: !70)
!88 = distinct !{!88, !72, !89, !52}
!89 = !DILocation(line: 22, column: 9, scope: !66)
!90 = !DILocation(line: 23, column: 5, scope: !67)
!91 = !DILocation(line: 17, column: 35, scope: !62)
!92 = !DILocation(line: 17, column: 5, scope: !62)
!93 = distinct !{!93, !64, !94, !52}
!94 = !DILocation(line: 23, column: 5, scope: !59)
!95 = !DILocation(line: 24, column: 1, scope: !8)
!96 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 26, type: !97, scopeLine: 26, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!97 = !DISubroutineType(types: !98)
!98 = !{!13}
!99 = !DILocalVariable(name: "a", scope: !96, file: !1, line: 29, type: !100)
!100 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 800, elements: !101)
!101 = !{!15, !15}
!102 = !DILocation(line: 29, column: 9, scope: !96)
!103 = !DILocation(line: 31, column: 14, scope: !96)
!104 = !DILocation(line: 31, column: 5, scope: !96)
!105 = !DILocalVariable(name: "a_size", scope: !96, file: !1, line: 33, type: !13)
!106 = !DILocation(line: 33, column: 9, scope: !96)
!107 = !DILocation(line: 34, column: 29, scope: !96)
!108 = !DILocation(line: 34, column: 5, scope: !96)
!109 = !DILocalVariable(name: "i", scope: !110, file: !1, line: 37, type: !13)
!110 = distinct !DILexicalBlock(scope: !96, file: !1, line: 37, column: 5)
!111 = !DILocation(line: 37, column: 14, scope: !110)
!112 = !DILocation(line: 37, column: 10, scope: !110)
!113 = !DILocation(line: 37, column: 21, scope: !114)
!114 = distinct !DILexicalBlock(scope: !110, file: !1, line: 37, column: 5)
!115 = !DILocation(line: 37, column: 23, scope: !114)
!116 = !DILocation(line: 37, column: 5, scope: !110)
!117 = !DILocalVariable(name: "j", scope: !118, file: !1, line: 38, type: !13)
!118 = distinct !DILexicalBlock(scope: !119, file: !1, line: 38, column: 9)
!119 = distinct !DILexicalBlock(scope: !114, file: !1, line: 37, column: 33)
!120 = !DILocation(line: 38, column: 18, scope: !118)
!121 = !DILocation(line: 38, column: 14, scope: !118)
!122 = !DILocation(line: 38, column: 25, scope: !123)
!123 = distinct !DILexicalBlock(scope: !118, file: !1, line: 38, column: 9)
!124 = !DILocation(line: 38, column: 27, scope: !123)
!125 = !DILocation(line: 38, column: 9, scope: !118)
!126 = !DILocation(line: 39, column: 29, scope: !127)
!127 = distinct !DILexicalBlock(scope: !123, file: !1, line: 38, column: 37)
!128 = !DILocation(line: 39, column: 27, scope: !127)
!129 = !DILocation(line: 39, column: 32, scope: !127)
!130 = !DILocation(line: 39, column: 13, scope: !127)
!131 = !DILocation(line: 40, column: 9, scope: !127)
!132 = !DILocation(line: 38, column: 33, scope: !123)
!133 = !DILocation(line: 38, column: 9, scope: !123)
!134 = distinct !{!134, !125, !135, !52}
!135 = !DILocation(line: 40, column: 9, scope: !118)
!136 = !DILocation(line: 41, column: 9, scope: !119)
!137 = !DILocation(line: 42, column: 5, scope: !119)
!138 = !DILocation(line: 37, column: 29, scope: !114)
!139 = !DILocation(line: 37, column: 5, scope: !114)
!140 = distinct !{!140, !116, !141, !52}
!141 = !DILocation(line: 42, column: 5, scope: !110)
!142 = !DILocation(line: 44, column: 5, scope: !96)
