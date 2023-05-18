; ModuleID = 'some_pattern.ll'
source_filename = "some_pattern.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@.str.1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local void @array_access_pattern(i32 noundef %rows, i32 noundef %cols, i32* noundef %arr) #0 !dbg !8 {
entry:
  call void @llvm.dbg.value(metadata i32 %rows, metadata !17, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.value(metadata i32 %cols, metadata !19, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.value(metadata i32* %arr, metadata !20, metadata !DIExpression()), !dbg !18
  %0 = zext i32 %cols to i64
  call void @llvm.dbg.value(metadata i32 0, metadata !21, metadata !DIExpression()), !dbg !23
  %cmp9 = icmp sgt i32 %rows, 0, !dbg !24
  br i1 %cmp9, label %for.cond1.preheader.lr.ph, label %for.cond10.preheader, !dbg !26

for.cond1.preheader.lr.ph:                        ; preds = %entry
  %wide.trip.count23 = zext i32 %rows to i64, !dbg !24
  br label %for.cond1.preheader, !dbg !26

for.cond1.preheader:                              ; preds = %for.cond1.preheader.lr.ph, %for.inc6
  %indvars.iv21 = phi i64 [ 0, %for.cond1.preheader.lr.ph ], [ %indvars.iv.next22, %for.inc6 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv21, metadata !21, metadata !DIExpression()), !dbg !23
  call void @llvm.dbg.value(metadata i32 0, metadata !27, metadata !DIExpression()), !dbg !30
  %cmp27 = icmp sgt i32 %cols, 0, !dbg !31
  br i1 %cmp27, label %for.body3.lr.ph, label %for.inc6, !dbg !33

for.body3.lr.ph:                                  ; preds = %for.cond1.preheader
  %wide.trip.count19 = zext i32 %cols to i64, !dbg !31
  br label %for.body3, !dbg !33

for.cond.for.cond10.preheader_crit_edge:          ; preds = %for.inc6
  br label %for.cond10.preheader, !dbg !26

for.cond10.preheader:                             ; preds = %for.cond.for.cond10.preheader_crit_edge, %entry
  call void @llvm.dbg.value(metadata i32 0, metadata !34, metadata !DIExpression()), !dbg !36
  %cmp114 = icmp sgt i32 %rows, 0, !dbg !37
  br i1 %cmp114, label %for.cond14.preheader.lr.ph, label %for.end27, !dbg !39

for.cond14.preheader.lr.ph:                       ; preds = %for.cond10.preheader
  %wide.trip.count15 = zext i32 %rows to i64, !dbg !37
  br label %for.cond14.preheader, !dbg !39

for.body3:                                        ; preds = %for.body3.lr.ph, %for.body3
  %indvars.iv17 = phi i64 [ 0, %for.body3.lr.ph ], [ %indvars.iv.next18, %for.body3 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv17, metadata !27, metadata !DIExpression()), !dbg !30
  %1 = mul nuw nsw i64 %indvars.iv21, %0, !dbg !40
  %arrayidx = getelementptr inbounds i32, i32* %arr, i64 %1, !dbg !40
  %arrayidx5 = getelementptr inbounds i32, i32* %arrayidx, i64 %indvars.iv17, !dbg !40
  store i32 0, i32* %arrayidx5, align 4, !dbg !42
  %indvars.iv.next18 = add nuw nsw i64 %indvars.iv17, 1, !dbg !43
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next18, metadata !27, metadata !DIExpression()), !dbg !30
  %exitcond20 = icmp ne i64 %indvars.iv.next18, %wide.trip.count19, !dbg !31
  br i1 %exitcond20, label %for.body3, label %for.cond1.for.inc6_crit_edge, !dbg !33, !llvm.loop !44

for.cond1.for.inc6_crit_edge:                     ; preds = %for.body3
  br label %for.inc6, !dbg !33

for.inc6:                                         ; preds = %for.cond1.for.inc6_crit_edge, %for.cond1.preheader
  %indvars.iv.next22 = add nuw nsw i64 %indvars.iv21, 1, !dbg !47
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next22, metadata !21, metadata !DIExpression()), !dbg !23
  %exitcond24 = icmp ne i64 %indvars.iv.next22, %wide.trip.count23, !dbg !24
  br i1 %exitcond24, label %for.cond1.preheader, label %for.cond.for.cond10.preheader_crit_edge, !dbg !26, !llvm.loop !48

for.cond14.preheader:                             ; preds = %for.cond14.preheader.lr.ph, %for.inc25
  %indvars.iv13 = phi i64 [ 0, %for.cond14.preheader.lr.ph ], [ %indvars.iv.next14, %for.inc25 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv13, metadata !34, metadata !DIExpression()), !dbg !36
  call void @llvm.dbg.value(metadata i32 0, metadata !50, metadata !DIExpression()), !dbg !53
  %cmp151 = icmp sgt i32 %cols, 0, !dbg !54
  br i1 %cmp151, label %for.body16.lr.ph, label %for.inc25, !dbg !56

for.body16.lr.ph:                                 ; preds = %for.cond14.preheader
  %wide.trip.count = zext i32 %cols to i64, !dbg !54
  br label %for.body16, !dbg !56

for.body16:                                       ; preds = %for.body16.lr.ph, %for.inc22
  %indvars.iv = phi i64 [ 0, %for.body16.lr.ph ], [ %indvars.iv.next, %for.inc22 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv, metadata !50, metadata !DIExpression()), !dbg !53
  %2 = add nuw nsw i64 %indvars.iv, %indvars.iv13, !dbg !57
  %3 = trunc i64 %2 to i32, !dbg !60
  %rem = and i32 %3, 1, !dbg !60
  %cmp17 = icmp eq i32 %rem, 0, !dbg !61
  br i1 %cmp17, label %if.then, label %for.inc22, !dbg !62

if.then:                                          ; preds = %for.body16
  %4 = mul nuw nsw i64 %indvars.iv13, %0, !dbg !63
  %arrayidx19 = getelementptr inbounds i32, i32* %arr, i64 %4, !dbg !63
  %arrayidx21 = getelementptr inbounds i32, i32* %arrayidx19, i64 %indvars.iv, !dbg !63
  store i32 1, i32* %arrayidx21, align 4, !dbg !65
  br label %for.inc22, !dbg !66

for.inc22:                                        ; preds = %for.body16, %if.then
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1, !dbg !67
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next, metadata !50, metadata !DIExpression()), !dbg !53
  %exitcond = icmp ne i64 %indvars.iv.next, %wide.trip.count, !dbg !54
  br i1 %exitcond, label %for.body16, label %for.cond14.for.inc25_crit_edge, !dbg !56, !llvm.loop !68

for.cond14.for.inc25_crit_edge:                   ; preds = %for.inc22
  br label %for.inc25, !dbg !56

for.inc25:                                        ; preds = %for.cond14.for.inc25_crit_edge, %for.cond14.preheader
  %indvars.iv.next14 = add nuw nsw i64 %indvars.iv13, 1, !dbg !70
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next14, metadata !34, metadata !DIExpression()), !dbg !36
  %exitcond16 = icmp ne i64 %indvars.iv.next14, %wide.trip.count15, !dbg !37
  br i1 %exitcond16, label %for.cond14.preheader, label %for.cond10.for.end27_crit_edge, !dbg !39, !llvm.loop !71

for.cond10.for.end27_crit_edge:                   ; preds = %for.inc25
  br label %for.end27, !dbg !39

for.end27:                                        ; preds = %for.cond10.for.end27_crit_edge, %for.cond10.preheader
  ret void, !dbg !73
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !74 {
entry:
  %arr = alloca [5 x [5 x i32]], align 16
  call void @llvm.dbg.declare(metadata [5 x [5 x i32]]* %arr, metadata !77, metadata !DIExpression()), !dbg !81
  %0 = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %arr, i64 0, i64 0, i64 0, !dbg !82
  call void @array_access_pattern(i32 noundef 5, i32 noundef 5, i32* noundef nonnull %0), !dbg !83
  call void @llvm.dbg.value(metadata i32 0, metadata !84, metadata !DIExpression()), !dbg !86
  br label %for.cond1.preheader, !dbg !87

for.cond1.preheader:                              ; preds = %entry, %for.end
  %indvars.iv3 = phi i64 [ 0, %entry ], [ %indvars.iv.next4, %for.end ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv3, metadata !84, metadata !DIExpression()), !dbg !86
  call void @llvm.dbg.value(metadata i32 0, metadata !88, metadata !DIExpression()), !dbg !92
  br label %for.body3, !dbg !93

for.body3:                                        ; preds = %for.cond1.preheader, %for.body3
  %indvars.iv = phi i64 [ 0, %for.cond1.preheader ], [ %indvars.iv.next, %for.body3 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv, metadata !88, metadata !DIExpression()), !dbg !92
  %arrayidx5 = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %arr, i64 0, i64 %indvars.iv3, i64 %indvars.iv, !dbg !94
  %1 = load i32, i32* %arrayidx5, align 4, !dbg !94
  %call = call i32 (i8*, ...) @printf(i8* noundef nonnull dereferenceable(1) getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 noundef %1) #4, !dbg !97
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1, !dbg !98
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next, metadata !88, metadata !DIExpression()), !dbg !92
  %exitcond = icmp ne i64 %indvars.iv.next, 5, !dbg !99
  br i1 %exitcond, label %for.body3, label %for.end, !dbg !93, !llvm.loop !100

for.end:                                          ; preds = %for.body3
  %putchar = call i32 @putchar(i32 10), !dbg !102
  %indvars.iv.next4 = add nuw nsw i64 %indvars.iv3, 1, !dbg !103
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next4, metadata !84, metadata !DIExpression()), !dbg !86
  %exitcond5 = icmp ne i64 %indvars.iv.next4, 5, !dbg !104
  br i1 %exitcond5, label %for.cond1.preheader, label %for.end9, !dbg !87, !llvm.loop !105

for.end9:                                         ; preds = %for.end
  ret i32 0, !dbg !107
}

declare dso_local i32 @printf(i8* noundef, ...) #2

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #1

; Function Attrs: nofree nounwind
declare noundef i32 @putchar(i32 noundef) #3

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nofree nounwind }
attributes #4 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "some_pattern.c", directory: "/home/users/shravank/projects/meliora2/Meliora/examples_mel", checksumkind: CSK_MD5, checksum: "8677063f869ac7f13f53186d72a11db6")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"uwtable", i32 1}
!6 = !{i32 7, !"frame-pointer", i32 2}
!7 = !{!"clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)"}
!8 = distinct !DISubprogram(name: "array_access_pattern", scope: !1, file: !1, line: 12, type: !9, scopeLine: 12, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!9 = !DISubroutineType(types: !10)
!10 = !{null, !11, !11, !12}
!11 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!12 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!13 = !DICompositeType(tag: DW_TAG_array_type, baseType: !11, elements: !14)
!14 = !{!15}
!15 = !DISubrange(count: -1)
!16 = !{}
!17 = !DILocalVariable(name: "rows", arg: 1, scope: !8, file: !1, line: 12, type: !11)
!18 = !DILocation(line: 0, scope: !8)
!19 = !DILocalVariable(name: "cols", arg: 2, scope: !8, file: !1, line: 12, type: !11)
!20 = !DILocalVariable(name: "arr", arg: 3, scope: !8, file: !1, line: 12, type: !12)
!21 = !DILocalVariable(name: "i", scope: !22, file: !1, line: 14, type: !11)
!22 = distinct !DILexicalBlock(scope: !8, file: !1, line: 14, column: 5)
!23 = !DILocation(line: 0, scope: !22)
!24 = !DILocation(line: 14, column: 23, scope: !25)
!25 = distinct !DILexicalBlock(scope: !22, file: !1, line: 14, column: 5)
!26 = !DILocation(line: 14, column: 5, scope: !22)
!27 = !DILocalVariable(name: "j", scope: !28, file: !1, line: 15, type: !11)
!28 = distinct !DILexicalBlock(scope: !29, file: !1, line: 15, column: 9)
!29 = distinct !DILexicalBlock(scope: !25, file: !1, line: 14, column: 36)
!30 = !DILocation(line: 0, scope: !28)
!31 = !DILocation(line: 15, column: 27, scope: !32)
!32 = distinct !DILexicalBlock(scope: !28, file: !1, line: 15, column: 9)
!33 = !DILocation(line: 15, column: 9, scope: !28)
!34 = !DILocalVariable(name: "i", scope: !35, file: !1, line: 21, type: !11)
!35 = distinct !DILexicalBlock(scope: !8, file: !1, line: 21, column: 5)
!36 = !DILocation(line: 0, scope: !35)
!37 = !DILocation(line: 21, column: 23, scope: !38)
!38 = distinct !DILexicalBlock(scope: !35, file: !1, line: 21, column: 5)
!39 = !DILocation(line: 21, column: 5, scope: !35)
!40 = !DILocation(line: 16, column: 13, scope: !41)
!41 = distinct !DILexicalBlock(scope: !32, file: !1, line: 15, column: 40)
!42 = !DILocation(line: 16, column: 23, scope: !41)
!43 = !DILocation(line: 15, column: 36, scope: !32)
!44 = distinct !{!44, !33, !45, !46}
!45 = !DILocation(line: 17, column: 9, scope: !28)
!46 = !{!"llvm.loop.mustprogress"}
!47 = !DILocation(line: 14, column: 32, scope: !25)
!48 = distinct !{!48, !26, !49, !46}
!49 = !DILocation(line: 18, column: 5, scope: !22)
!50 = !DILocalVariable(name: "j", scope: !51, file: !1, line: 22, type: !11)
!51 = distinct !DILexicalBlock(scope: !52, file: !1, line: 22, column: 9)
!52 = distinct !DILexicalBlock(scope: !38, file: !1, line: 21, column: 36)
!53 = !DILocation(line: 0, scope: !51)
!54 = !DILocation(line: 22, column: 27, scope: !55)
!55 = distinct !DILexicalBlock(scope: !51, file: !1, line: 22, column: 9)
!56 = !DILocation(line: 22, column: 9, scope: !51)
!57 = !DILocation(line: 23, column: 20, scope: !58)
!58 = distinct !DILexicalBlock(scope: !59, file: !1, line: 23, column: 17)
!59 = distinct !DILexicalBlock(scope: !55, file: !1, line: 22, column: 40)
!60 = !DILocation(line: 23, column: 25, scope: !58)
!61 = !DILocation(line: 23, column: 29, scope: !58)
!62 = !DILocation(line: 23, column: 17, scope: !59)
!63 = !DILocation(line: 24, column: 17, scope: !64)
!64 = distinct !DILexicalBlock(scope: !58, file: !1, line: 23, column: 35)
!65 = !DILocation(line: 24, column: 27, scope: !64)
!66 = !DILocation(line: 25, column: 13, scope: !64)
!67 = !DILocation(line: 22, column: 36, scope: !55)
!68 = distinct !{!68, !56, !69, !46}
!69 = !DILocation(line: 26, column: 9, scope: !51)
!70 = !DILocation(line: 21, column: 32, scope: !38)
!71 = distinct !{!71, !39, !72, !46}
!72 = !DILocation(line: 27, column: 5, scope: !35)
!73 = !DILocation(line: 28, column: 1, scope: !8)
!74 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 30, type: !75, scopeLine: 30, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!75 = !DISubroutineType(types: !76)
!76 = !{!11}
!77 = !DILocalVariable(name: "arr", scope: !74, file: !1, line: 31, type: !78)
!78 = !DICompositeType(tag: DW_TAG_array_type, baseType: !11, size: 800, elements: !79)
!79 = !{!80, !80}
!80 = !DISubrange(count: 5)
!81 = !DILocation(line: 31, column: 9, scope: !74)
!82 = !DILocation(line: 32, column: 32, scope: !74)
!83 = !DILocation(line: 32, column: 5, scope: !74)
!84 = !DILocalVariable(name: "i", scope: !85, file: !1, line: 35, type: !11)
!85 = distinct !DILexicalBlock(scope: !74, file: !1, line: 35, column: 5)
!86 = !DILocation(line: 0, scope: !85)
!87 = !DILocation(line: 35, column: 5, scope: !85)
!88 = !DILocalVariable(name: "j", scope: !89, file: !1, line: 36, type: !11)
!89 = distinct !DILexicalBlock(scope: !90, file: !1, line: 36, column: 9)
!90 = distinct !DILexicalBlock(scope: !91, file: !1, line: 35, column: 33)
!91 = distinct !DILexicalBlock(scope: !85, file: !1, line: 35, column: 5)
!92 = !DILocation(line: 0, scope: !89)
!93 = !DILocation(line: 36, column: 9, scope: !89)
!94 = !DILocation(line: 37, column: 27, scope: !95)
!95 = distinct !DILexicalBlock(scope: !96, file: !1, line: 36, column: 37)
!96 = distinct !DILexicalBlock(scope: !89, file: !1, line: 36, column: 9)
!97 = !DILocation(line: 37, column: 13, scope: !95)
!98 = !DILocation(line: 36, column: 33, scope: !96)
!99 = !DILocation(line: 36, column: 27, scope: !96)
!100 = distinct !{!100, !93, !101, !46}
!101 = !DILocation(line: 38, column: 9, scope: !89)
!102 = !DILocation(line: 39, column: 9, scope: !90)
!103 = !DILocation(line: 35, column: 29, scope: !91)
!104 = !DILocation(line: 35, column: 23, scope: !91)
!105 = distinct !{!105, !87, !106, !46}
!106 = !DILocation(line: 40, column: 5, scope: !85)
!107 = !DILocation(line: 42, column: 5, scope: !74)
